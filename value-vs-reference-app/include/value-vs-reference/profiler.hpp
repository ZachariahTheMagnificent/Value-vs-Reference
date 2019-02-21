#pragma once
#include <vector>
#include <algorithm>
#include <numeric>
#include <chrono>

struct profiler
{
	using clock = std::chrono::steady_clock;
	using time_point = clock::time_point;
	using duration = clock::duration;
	using num_type = duration::rep;

	struct profile
	{
		profile ( ) = default;
		explicit profile ( const num_type lowest, const num_type highest, const num_type median, const num_type mean, const num_type standard_deviation ) noexcept : lowest ( lowest ),
			highest ( highest ),
			median ( median ),
			mean ( mean ),
			standard_deviation ( standard_deviation )
		{

		}

		num_type lowest = num_type ( );
		num_type highest = num_type ( );
		num_type median = num_type ( );
		num_type mean = num_type ( );
		num_type standard_deviation = num_type ( );
	};

	profiler ( ) = default;
	explicit profiler ( const size_t size )
	{
		data_points_.reserve ( size );
	}

	void start ( )
	{
		last_time_point_ = clock::now ( );
	}
	void end ( )
	{
		const auto curr_time_point = clock::now ( );
		const auto duration = curr_time_point - last_time_point_;
		const auto num_representation = duration.count ( );
		data_points_.push_back ( num_representation );
		last_time_point_ = curr_time_point;
	}

	profile flush ( )
	{
		std::sort ( data_points_.begin ( ), data_points_.end ( ) );

		const auto begin = data_points_.cbegin ( );
		const auto end = data_points_.cend ( );
		const auto size = data_points_.size ( );

		const auto lowest = data_points_.front ( );
		const auto highest = data_points_.back ( );
		const auto median = data_points_ [ size / 2 ];
		const auto sum = std::accumulate ( begin, end, static_cast<num_type>( 0 ) );
		const auto mean = sum / size;
		const auto standard_deviation = std::sqrt ( std::accumulate ( begin, end, static_cast<num_type>( 0 ), [ mean ] ( const auto& total, const auto& point )
		{
			const auto difference = point - mean;
			return total + difference * difference;
		} ) / static_cast <long double> ( size ) );

		data_points_.clear ( );

		return profile (
			static_cast<num_type>( lowest ),
			static_cast<num_type>( highest ),
			static_cast<num_type>( median ),
			static_cast<num_type>( mean ),
			static_cast<num_type>( standard_deviation ) );
	}

private:
	std::vector<num_type> data_points_;
	time_point last_time_point_;

};

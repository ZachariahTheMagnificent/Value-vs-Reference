#include <iostream>
#include <vector>
#include <random>
#include "profiler.hpp"

//#define VALUE_SEMANTICS_FOR_STRUCTS
//#define REFERENCE_SEMANTICS_FOR_BASIC_TYPES
#define USE_DOUBLES

using real =
#if defined USE_DOUBLES
double
#else
float
#endif
;

using real_parameter = const real
#if defined REFERENCE_SEMANTICS_FOR_BASIC_TYPES
&
#endif
;

struct vector;
using vector_parameter = const vector
#if !defined VALUE_SEMANTICS_FOR_STRUCTS
&
#endif
;

struct vector
{
	real x { };
	real y { };

	vector ( ) = default;
	constexpr explicit vector ( real_parameter x, real_parameter y ) noexcept : x { x }, y { y }
	{

	}

	constexpr auto operator+= ( vector_parameter rhs ) noexcept
	{
		x += rhs.x;
		y += rhs.y;

		return *this;
	}
	constexpr auto operator-= ( vector_parameter rhs ) noexcept
	{
		x -= rhs.x;
		y -= rhs.y;

		return *this;
	}
	const auto operator*= ( real_parameter rhs ) noexcept
	{
		x *= rhs;
		y *= rhs;

		return *this;
	}
	const auto operator/= ( const real_parameter rhs ) noexcept
	{
		x /= rhs;
		y /= rhs;

		return *this;
	}

	constexpr auto operator+ ( vector_parameter rhs ) const noexcept
	{
		return vector { x + rhs.x, y + rhs.y };
	}
	constexpr auto operator- ( vector_parameter rhs ) const noexcept
	{
		return vector { x - rhs.x, y - rhs.y };
	}
	constexpr auto operator* ( real_parameter rhs ) const noexcept
	{
		return vector { x * rhs, y * rhs };
	}
	constexpr auto operator/ ( real_parameter rhs ) const noexcept
	{
		return vector { x / rhs, y / rhs };
	}
};

struct car
{
	vector acceleration { };
	vector velocity { };
	vector position { };
	
	car ( ) = default;
	constexpr explicit car ( vector_parameter acceleration, vector_parameter velocity, vector_parameter position ) noexcept : acceleration { acceleration },
		velocity { velocity },
		position { position }
	{

	}

	constexpr void update ( real_parameter delta_time ) noexcept
	{
		velocity += acceleration * delta_time;
		position += velocity * delta_time;
	}
};

int main ( )
{
	constexpr auto num_tests = std::size_t { 1000 };
	constexpr auto num_objects = std::size_t { 10000 };
	constexpr auto min_acceleration_x = real { 3.f };
	constexpr auto max_acceleration_x = real { 5.f };
	constexpr auto min_acceleration_y = real { 3.f };
	constexpr auto max_acceleration_y = real { 5.f };
	constexpr auto min_velocity_x = real { 3.f };
	constexpr auto max_velocity_x = real { 5.f };
	constexpr auto min_velocity_y = real { 3.f };
	constexpr auto max_velocity_y = real { 5.f };
	constexpr auto delta_time = real { 0.001f };

	auto my_profiler = profiler ( );
	auto cars = std::vector<car> { };
	auto rng_machine = std::mt19937 { };
	auto acceleration_x_generator = std::uniform_real_distribution<real> { min_acceleration_x, max_acceleration_x };
	auto acceleration_y_generator = std::uniform_real_distribution<real> { min_acceleration_y, max_acceleration_y };
	auto velocity_x_generator = std::uniform_real_distribution<real> { min_velocity_x, max_velocity_x };
	auto velocity_y_generator = std::uniform_real_distribution<real> { min_velocity_y, max_velocity_y };

	for ( auto i = std::size_t { }; i < num_objects; ++i )
	{
		const auto acceleration = vector { acceleration_x_generator ( rng_machine ), acceleration_y_generator ( rng_machine ) };
		const auto velocity = vector { velocity_x_generator ( rng_machine ), velocity_y_generator ( rng_machine ) };
		const auto position = vector { };

		cars.emplace_back ( acceleration, velocity, position );
	}

	for ( auto i = std::size_t { }; i < num_tests; ++i )
	{
		my_profiler.start ( );
		for ( auto& my_car : cars )
		{
			my_car.update ( delta_time );
		}
		my_profiler.end ( );
	}

	auto my_profile = my_profiler.flush ( );

	std::cout << "Average: " << my_profile.mean << "ns\n";
	std::cout << "Highest: " << my_profile.highest << "ns\n";
	std::cout << "Lowest: " << my_profile.lowest << "ns\n";
	std::cout << "Median: " << my_profile.median << "ns\n";
	std::cout << "Standard Deviation: " << my_profile.standard_deviation << "ns\n";

	std::system ( "pause" );
	return 0;
}

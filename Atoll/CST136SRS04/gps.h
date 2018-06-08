#pragma once
#include <string>
#include "range.h"

namespace GPS
{
	template<int min, int max>
	class Angle
	{
		static_assert(min < max);

	private:
		using base_degree_type = int;
		using base_minute_type = unsigned;
		using base_second_type = unsigned;

	protected:
		using degree_type = Range<base_degree_type, min, max>;
		using minute_type = Range<base_minute_type, 0, 60>;
		using second_type = Range<base_second_type, 0, 60>;

		const degree_type degree_;
		const minute_type minute_;
		const second_type second_;

	public:
		Angle(const degree_type degree, const minute_type minute, const second_type second);
	};
	template<int min, int max>
	inline Angle<min, max>::Angle(const degree_type degree, const minute_type minute, const second_type second) : degree_(degree), minute_(minute), second_(second)
	{	}
}

namespace GPS
{
	class Latitude : public Angle<-89, 90>
	{
	public:
		enum class Cardinal { S = -1, N = +1 };

		Cardinal cardinallat_;

		double coordinate() const
		{
			return degree_.getvalue() + minute_.getvalue()/60 + second_.getvalue()/3600;
		}

		Latitude(const Cardinal cardinal, const degree_type degree, const minute_type minute, const second_type second);
	};
}

namespace GPS
{
	class Longitude : public Angle<-180, 180>
	{
	public:
		enum class Cardinal { W = -1, E = +1 };

		Cardinal cardinallong_;

		double coordinate() const
		{
			return degree_.getvalue() + minute_.getvalue()/60 + second_.getvalue()/3600;
		}

		Longitude(const Cardinal cardinal, const degree_type degree, const minute_type minute, const second_type second);
	};
}

namespace GPS
{
	class Location
	{
	private:
		const std::string name_;
		const Latitude latitude_;
		const Longitude longitude_;

	public:
		Location(const std::string name, const Latitude latitude, const Longitude longitude);

		double latcord() const;
		double lngcord() const;
	};
}
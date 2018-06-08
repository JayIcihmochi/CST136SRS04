#include "stdafx.h"
#include "gps.h"

GPS::Latitude::Latitude(const Cardinal cardinal, const degree_type degree, const minute_type minute, const second_type second) : Angle(degree, minute, second), cardinallat_(cardinal)
{	}

GPS::Longitude::Longitude(const Cardinal cardinal, const degree_type degree, const minute_type minute, const second_type second) : Angle(degree, minute, second), cardinallong_(cardinal)
{	}

GPS::Location::Location(const std::string name, const Latitude latitude, const Longitude longitude) : name_(name), latitude_(latitude), longitude_(longitude)
{	}

double GPS::Location::latcord() const
{
	if (latitude_.cardinallat_ == Latitude::Cardinal::S)
	{
		return -latitude_.coordinate();
	}
	return latitude_.coordinate();
}

double GPS::Location::lngcord() const
{
	if (longitude_.cardinallong_ == Longitude::Cardinal::E)
	{
		return -longitude_.coordinate();
	}
	return longitude_.coordinate() - 360;
}
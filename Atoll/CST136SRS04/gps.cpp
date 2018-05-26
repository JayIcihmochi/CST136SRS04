#include "stdafx.h"
#include "gps.h"

GPS::Latitude::Latitude(const Cardinal cardinal, const degree_type degree, const minute_type minute, const second_type second) : Angle(degree, minute, second), cardinallat_(cardinal)
{	}

GPS::Longitude::Longitude(const Cardinal cardinal, const degree_type degree, const minute_type minute, const second_type second) : Angle(degree, minute, second), cardinallong_(cardinal)
{	}

GPS::Location::Location(const std::string name, const Latitude latitude, const Longitude longitude) : name_(name), latitude_(latitude), longitude_(longitude)
{	}
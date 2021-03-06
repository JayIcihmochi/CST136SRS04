#include "stdafx.h"
#include <numeric>
#include <array>
#include <algorithm>
#include <forward_list>
#include <vector>
#include <map>
#include <cmath>
#include "gps.h"
#define earthradius 6378

bool latcmp(const GPS::Location & a, const GPS::Location & b)
{
	return a.latcord() < b.latcord();
}

bool lngcmp(const GPS::Location & a, const GPS::Location & b)
{
	return a.lngcord() > b.lngcord();
}

int main()
{
	std::array<GPS::Location, 12> island
	{
		GPS::Location{ "Faichuk Islands",	GPS::Latitude{ GPS::Latitude::Cardinal::N, 7, 21, 8 },		GPS::Longitude{ GPS::Longitude::Cardinal::E, 151, 36, 30 } },
		GPS::Location{ "Hawaii",			GPS::Latitude{ GPS::Latitude::Cardinal::N, 21, 18, 41 },	GPS::Longitude{ GPS::Longitude::Cardinal::W, 157, 47, 47 } },
		GPS::Location{ "Mariana Islands",	GPS::Latitude{ GPS::Latitude::Cardinal::N, 17, 0, 0 },		GPS::Longitude{ GPS::Longitude::Cardinal::E, 146, 0, 0 } },
		GPS::Location{ "Johnston Atoll",	GPS::Latitude{ GPS::Latitude::Cardinal::N, 16, 44, 13 },	GPS::Longitude{ GPS::Longitude::Cardinal::W, 169, 31, 26 } },
		GPS::Location{ "Kosrae",			GPS::Latitude{ GPS::Latitude::Cardinal::N, 5, 19, 0 },		GPS::Longitude{ GPS::Longitude::Cardinal::E, 162, 59, 0 } },
		GPS::Location{ "Falalop",			GPS::Latitude{ GPS::Latitude::Cardinal::N, 10, 1, 14 },		GPS::Longitude{ GPS::Longitude::Cardinal::E, 139, 47, 23 } },
		GPS::Location{ "Guam",				GPS::Latitude{ GPS::Latitude::Cardinal::N, 13, 30, 0 },		GPS::Longitude{ GPS::Longitude::Cardinal::E, 144, 48, 0 } },
		GPS::Location{ "Pohnpei",			GPS::Latitude{ GPS::Latitude::Cardinal::N, 6, 51, 0 },		GPS::Longitude{ GPS::Longitude::Cardinal::E, 158, 13, 0 } },
		GPS::Location{ "Marshall Islands",	GPS::Latitude{ GPS::Latitude::Cardinal::N, 7, 7, 0 },		GPS::Longitude{ GPS::Longitude::Cardinal::E, 171, 4, 0 } },
		GPS::Location{ "Yap",				GPS::Latitude{ GPS::Latitude::Cardinal::N, 9, 32, 0 },		GPS::Longitude{ GPS::Longitude::Cardinal::E, 138, 7, 0 } },
		GPS::Location{ "Wake Island",		GPS::Latitude{ GPS::Latitude::Cardinal::N, 19, 17, 43 },	GPS::Longitude{ GPS::Longitude::Cardinal::E, 166, 37, 52 } },
		GPS::Location{ "New Zealand",		GPS::Latitude{ GPS::Latitude::Cardinal::S, 41, 17, 0 },		GPS::Longitude{ GPS::Longitude::Cardinal::E, 174, 27, 0 } }
	};

	std::vector<double> sum;


	std::forward_list<GPS::Location> islandforwardlist{ island.begin(), island.end() };
	islandforwardlist.sort(latcmp);

	auto it{ islandforwardlist.begin() };
	++it;
	for (auto ptr = islandforwardlist.begin(); it != islandforwardlist.end() ; ++ptr, ++it)
	{
		GPS::Location temp{ *ptr };
		GPS::Location temp2{ *it };

		const double lat1{ temp.latcord() };
		const double lat2{ temp2.latcord() };
		const double lng1{ temp.lngcord() };
		const double lng2{ temp2.lngcord() };

		double distence = 2 * earthradius * (sqrt(pow(sin((lat2 - lat1) / 2), 2) + (cos(lat1) * cos(lat2) * pow(sin((lng2 - lng1) / 2), 2))));
		sum.push_back(distence);
	}
	double totalDistence1{ std::accumulate(sum.begin(), sum.end(), 0.0) };
	sum.clear();


	islandforwardlist.sort(lngcmp);

	it = islandforwardlist.begin();
	++it;
	for (auto ptr = islandforwardlist.begin(); it != islandforwardlist.end(); ++ptr, ++it)
	{
		GPS::Location temp{ *ptr };
		GPS::Location temp2{ *it };

		const double lat1{ temp.latcord() };
		const double lat2{ temp2.latcord() };
		const double lng1{ temp.lngcord() };
		const double lng2{ temp2.lngcord() };

		double distence = 2 * earthradius * (sqrt(pow(sin((lat2 - lat1) / 2), 2) + (cos(lat1) * cos(lat2) * pow(sin((lng2 - lng1) / 2), 2))));
		sum.push_back(distence);
	}
	double totalDistence2{ std::accumulate(sum.begin(), sum.end(), 0.0) };
	sum.clear();


	std::vector<std::reference_wrapper<GPS::Location>> islandvector { island.begin(), island.end() };
	std::sort(islandvector.begin(), islandvector.end(), latcmp);

	for(int i = 0; i < 11; i++)
	{
		GPS::Location temp{ islandvector.at(i) };
		GPS::Location temp2{ islandvector.at(i + 1) };

		const double lat1{ temp.latcord() };
		const double lat2{ temp2.latcord() };
		const double lng1{ temp.lngcord() };
		const double lng2{ temp2.lngcord() };

		double distence = 2 * earthradius * (sqrt(pow(sin((lat2 - lat1) / 2), 2) + (cos(lat1) * cos(lat2) * pow(sin((lng2 - lng1) / 2), 2))));
		sum.push_back(distence);
	}

	double totalDistence3{ std::accumulate(sum.begin(), sum.end(), 0.0) };
	sum.clear();

	std::sort(islandvector.begin(), islandvector.end(), lngcmp);

	for (int i = 0; i < 11; i++)
	{
		GPS::Location temp{ islandvector.at(i) };
		GPS::Location temp2{ islandvector.at(i + 1) };

		const double lat1{ temp.latcord() };
		const double lat2{ temp2.latcord() };
		const double lng1{ temp.lngcord() };
		const double lng2{ temp2.lngcord() };

		double distence = 2 * earthradius * (sqrt(pow(sin((lat2 - lat1) / 2), 2) + (cos(lat1) * cos(lat2) * pow(sin((lng2 - lng1) / 2), 2))));
		sum.push_back(distence);
	}
	double totalDistence4{ std::accumulate(sum.begin(), sum.end(), 0.0) };
	sum.clear();



	std::map<int, GPS::Location> islandmap;

	std::sort(islandvector.begin(), islandvector.end(), latcmp);

	for(int i = 0; i < islandvector.size(); i++)
	{
		islandmap.insert(std::pair<int, GPS::Location>(i, islandvector.at(i)));
	}
	for (int i = 0; i < 11; i++)
	{
		GPS::Location temp{ islandmap.at(i) };
		GPS::Location temp2{ islandmap.at(i + 1) };

		const double lat1{ temp.latcord() };
		const double lat2{ temp2.latcord() };
		const double lng1{ temp.lngcord() };
		const double lng2{ temp2.lngcord() };

		double distence = 2 * earthradius * (sqrt(pow(sin((lat2 - lat1) / 2), 2) + (cos(lat1) * cos(lat2) * pow(sin((lng2 - lng1) / 2), 2))));
		sum.push_back(distence);
	}
	double totalDistence5{ std::accumulate(sum.begin(), sum.end(), 0.0) };
	sum.clear();
	islandmap.clear();

	std::sort(islandvector.begin(), islandvector.end(), lngcmp);

	for (int i = 0; i < islandvector.size(); i++)
	{
		islandmap.insert(std::pair<int, GPS::Location>(i, islandvector.at(i)));
	}
	for (int i = 0; i < 11; i++)
	{
		GPS::Location temp{ islandmap.at(i) };
		GPS::Location temp2{ islandmap.at(i + 1) };

		const double lat1{ temp.latcord() };
		const double lat2{ temp2.latcord() };
		const double lng1{ temp.lngcord() };
		const double lng2{ temp2.lngcord() };

		double distence = 2 * earthradius * (sqrt(pow(sin((lat2 - lat1) / 2), 2) + (cos(lat1) * cos(lat2) * pow(sin((lng2 - lng1) / 2), 2))));
		sum.push_back(distence);
	}
	double totalDistence6{ std::accumulate(sum.begin(), sum.end(), 0.0) };

    return 0;
}
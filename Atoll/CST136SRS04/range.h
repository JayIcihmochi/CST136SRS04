#pragma once

template<typename T, T min, T max>
class Range
{
private:
	using value_type = T;

	value_type upper_{ max };
	value_type lower_{ min };
	value_type value_{ };

public:
	Range() = default;

	value_type setvalue(T);

};
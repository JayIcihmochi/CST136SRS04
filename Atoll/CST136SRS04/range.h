#pragma once

template<typename T, T min, T max>
class Range
{

private:
	using value_type = T;

	value_type upper_{ max };
	value_type lower_{ min };
	value_type value_{};

public:
	Range(value_type value);

	double getvalue() const;
};

template <typename T, T min, T max>
Range<T, min, max>::Range(value_type value) : value_(value)
{	}

template <typename T, T min, T max>
double Range<T, min, max>::getvalue() const
{
	return value_;
}
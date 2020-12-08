#include "CalendarCurrentMoment.h"

CalendarCurrentMoment::CalendarCurrentMoment()
{
	time_t right_now = time(0);
	tm right_now_struct;
	localtime_s(&right_now_struct, &right_now);

	m_current_day = right_now_struct.tm_mday;
	m_current_month = right_now_struct.tm_mon + 1;
	m_current_year = right_now_struct.tm_year + 1900;

	m_current_minute = right_now_struct.tm_min;
	m_current_hour = right_now_struct.tm_hour;
}
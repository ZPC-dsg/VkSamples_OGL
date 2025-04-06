# pragma once

#include <nocopyable.h>
#include <init.h>

#include <deque>
#include <optional>

class GpuTimer : NoCopyable
{
public:
	enum TimeMode {
		NanoSeconds,
		MicroSeconds,
		MiliSeconds,
		Seconds
	};

	GpuTimer(int frameCount = 1);
	~GpuTimer();

	float duration(const int index = -1, TimeMode mode = NanoSeconds);
	float average_duration(TimeMode mode = NanoSeconds);

	void start();
	void stop();
	void reset(int frameCount);

private:
	std::deque<std::optional<GLuint64>> m_timeInfos;
	int m_frameCount;
	int m_currFrame;
    GLuint64 m_accumulationTime;

	GLuint m_query;
};
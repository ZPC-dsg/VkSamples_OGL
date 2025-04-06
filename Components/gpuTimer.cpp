# include <gpuTimer.h>

#include <numeric>

GpuTimer::GpuTimer(int frameCount) :m_frameCount(frameCount), m_currFrame(0), m_accumulationTime(0) {
	assert(frameCount <= globalSettings::max_gpu_timer_count);

	m_timeInfos.resize(frameCount);

	glGenQueries(1, &m_query);
}

void GpuTimer::start() {
	glBeginQuery(GL_TIME_ELAPSED, m_query);
	m_timeInfos[m_currFrame] = -1;//设置为-1表明该时间戳查询已经启动，但没有完成
}

void GpuTimer::stop() {
	glEndQuery(GL_TIME_ELAPSED);
	GLuint64 temp;
	glGetQueryObjectui64v(m_query, GL_QUERY_RESULT, &temp);
	m_accumulationTime += temp - m_timeInfos[m_currFrame].value() == -1 ? 0 : m_timeInfos[m_currFrame].value();
	m_timeInfos[m_currFrame] = temp;
	m_currFrame = (m_currFrame + 1) % m_frameCount;
}

void GpuTimer::reset(int frameCount) {
	assert((!m_timeInfos[m_currFrame].has_value()) || m_timeInfos[m_currFrame].value() >= 0);

	m_frameCount = frameCount;
	m_currFrame = 0;
	m_accumulationTime = 0;
	m_timeInfos.clear();
	m_timeInfos.resize(m_frameCount);
}

float GpuTimer::duration(const int index, TimeMode mode) {
	assert(index < m_frameCount);

	float divisor = 1;
	switch (mode) {
	case NanoSeconds:
		break;
	case MicroSeconds:
		divisor = 1e3;
		break;
	case MiliSeconds:
		divisor = 1e6;
		break;
	case Seconds:
		divisor = 1e9;
		break;
	}

	if (index < 0) {//返回最近一次查询的时间
		return static_cast<float>(m_timeInfos[(m_currFrame - 1 + m_frameCount) % m_frameCount].value()) / divisor;
	}
	else {
		return static_cast<float>(m_timeInfos[index].value()) / divisor;
	}
}

float GpuTimer::average_duration(TimeMode mode) {
	if (m_frameCount == 1) {
		return duration(0, mode);
	}

	float divisor = 1;
	switch (mode) {
	case NanoSeconds:
		break;
	case MicroSeconds:
		divisor = 1e3;
		break;
	case MiliSeconds:
		divisor = 1e6;
		break;
	case Seconds:
		divisor = 1e9;
		break;
	}

	if ((!m_timeInfos[m_currFrame].has_value()) || m_timeInfos[m_currFrame].value() == -1) {
		assert(m_currFrame);

		return static_cast<float>(m_accumulationTime) / divisor / m_currFrame;
	}
	else {
		return static_cast<float>(m_accumulationTime) / divisor / m_frameCount;
	}
}

GpuTimer::~GpuTimer() {
	glDeleteQueries(1, &m_query);
}
#include <logging.h>

#include <spdlog/cfg/env.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace logging
{
	void init()
	{
		auto env_val = spdlog::details::os::getenv("RENDER_LOG_LEVEL");
		if (!env_val.empty())
		{
			spdlog::cfg::helpers::load_levels(env_val);
		}

		auto logger = spdlog::stdout_color_mt("logger");

		logger->set_pattern(LOGGER_FORMAT);
		logger->set_level(spdlog::level::trace);
		spdlog::set_default_logger(logger);
	}
}      
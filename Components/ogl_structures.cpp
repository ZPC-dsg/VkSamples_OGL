#include <ogl_structures.h>

std::string OGL_BLEND_STATE::GlobalTag(OGL_BLEND_STATE state) noexcept {
	return Resolver(state.src_blend_func, state.dst_blend_func, state.src_alp_blend_func, state.dst_alp_blend_func, state.blend_eq, state.blend_factor);
}

std::string OGL_DEPTH_STENCIL_STATE::GlobalTag(OGL_DEPTH_STENCIL_STATE state) noexcept {
	return Resolver(state.depth_enabled, state.depth_write_enabled, state.stencil_enabled, state.depth_compare_op, state.stencil_compare_op,
		state.stencil_compare_mask, state.stencil_write_mask, state.stencil_ref, state.stencil_fail_op, state.stencil_pass_depth_fail_op, state.depth_pass_op);
}

std::string OGL_RASTERIZER_STATE::GlobalTag(OGL_RASTERIZER_STATE state) noexcept {
	return Resolver(state.cull_enabled, state.polygon_offset_enabled, state.depth_clamp_enabled, state.fill_mode, state.cull_mode, state.front_face,
		state.line_width, state.point_size, state.depth_bias, state.slope_scaled_depth_bias);
}

std::string OGL_RECT::GlobalTag(OGL_RECT state) noexcept {
	return Resolver(state.x, state.y, state.width, state.height);
}

std::string OGL_VIEWPORT_SCISSOR_STATE::GlobalTag(OGL_VIEWPORT_SCISSOR_STATE state) noexcept {
	return Resolver(state.scissor_enabled) + OGL_RECT::GlobalTag(state.viewport) + OGL_RECT::GlobalTag(state.scissor);
}

std::string OGL_TEXTURE2D_DESC::GlobalTag(OGL_TEXTURE2D_DESC desc) noexcept {
	return Resolver(desc.target, desc.width, desc.height, desc.internal_format, desc.cpu_format, desc.data_type, desc.arrayslices, desc.samplecount,
		desc.fixed_sample_location);
}

std::string OGL_TEXTURE_PARAMETER::GlobalTag(OGL_TEXTURE_PARAMETER param) noexcept {
	return Resolver(param.min_filter, param.mag_filter, param.wrap_x, param.wrap_y, param.wrap_z, param.border_color);
}
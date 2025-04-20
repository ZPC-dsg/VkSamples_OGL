#pragma once

#ifdef _DEBUG
#define noxnd noexcept(false)
#else
#define noxnd noexcept(true)
#endif
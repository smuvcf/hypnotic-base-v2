#pragma once
#include <cstdint>

template <typename T = void *>
constexpr T vfunc( void * thisptr , std::size_t idx ) {
	return ( *static_cast< T ** >( thisptr ) )[ idx ];
}

template <typename t , typename ... args_t>
__forceinline t call_vfunc( void * thisptr , std::size_t nIndex , args_t... argList ) {
	using fn = t( __thiscall * )( void * , decltype( argList )... );
	return ( *static_cast< fn ** >( thisptr ) )[ nIndex ]( thisptr , argList... );
}
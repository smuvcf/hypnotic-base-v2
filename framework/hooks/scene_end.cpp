#include "scene_end.hpp"

decltype( &hooks::scene_end ) hooks::original::scene_end = nullptr;

void __fastcall hooks::scene_end( void* ecx, void* edx ) {
	original::scene_end( ecx, edx );

	for ( auto i = 0; i < csgo::i::glow_obj_mgr->m_size; i++ ) {
		if ( csgo::i::glow_obj_mgr->m_glow_object_definitions[i].is_unused( ) || !csgo::i::glow_obj_mgr->m_glow_object_definitions[i].get_entity( ) )
			continue;

		auto& glow_object = csgo::i::glow_obj_mgr->m_glow_object_definitions[i];
	}
}
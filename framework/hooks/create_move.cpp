#include "create_move.hpp"

decltype( &hooks::create_move ) hooks::original::create_move = nullptr;

bool __fastcall hooks::create_move( void* ecx, void* edx, float sampletime, ucmd_t* ucmd ) {
	if ( !ucmd || !ucmd->m_cmdnum )
		return false;

	auto local = csgo::i::ent_list->get<player_t*>( csgo::i::engine->get_local_player( ) );
	auto ret = original::create_move( ecx, edx, sampletime, ucmd );

	g::ucmd = ucmd;

	const auto backup_angle = ucmd->m_angs;
	const auto backup_sidemove = ucmd->m_smove;
	const auto backup_forwardmove = ucmd->m_fmove;

	features::prediction::run( [&] ( ) {
		} );

	csgo::clamp( ucmd->m_angs );
	csgo::rotate_movement( ucmd );
	csgo::fix_movement( ucmd );

	*( bool* ) ( *( uintptr_t* ) ( uintptr_t( _AddressOfReturnAddress( ) ) - 4 ) - 28 ) = g::send_packet;

	return false;
}
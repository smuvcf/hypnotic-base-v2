#pragma once
#include "../sdk/sdk.hpp"
#include "../globals.hpp"

class c_event_handler : c_event_listener {
public:
	c_event_handler( ) {
		csgo::i::events->add_listener( this, _( "weapon_fire" ), false );
		csgo::i::events->add_listener( this, _( "player_say" ), false );
		csgo::i::events->add_listener( this, _( "player_hurt" ), false );
		csgo::i::events->add_listener( this, _( "bullet_impact" ), false );
	}

	virtual ~c_event_handler( ) {
		csgo::i::events->remove_listener( this );
	}

	virtual void fire_game_event( event_t* event ) {
		if ( !event || !g::local )
			return;

		auto hash = fnv1a::hash( event->get_name( ) );

		switch ( hash ) {
		case fnv1a::hash_const( "player_hurt" ):
			break;
		}
	}

	int get_event_debug_id( ) override {
		return 42;
	}
};
std::unique_ptr< c_event_handler > event_handler;
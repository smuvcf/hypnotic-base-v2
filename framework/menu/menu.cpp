#include "menu.hpp"

void menu::render( ) {
	ngui::poll_input( "Counter-Strike: Global Offensive" );
	if ( ngui::begin_window( "csgo-sdk", opened, fonts::menu_bold, ngui::windowflags_centertitle ) ) {
		if ( ngui::tabs( { "tab1", "tab2" }, tab_value ) ) {
			if ( ngui::child( "group1", ngui::vec2( 185, 215 ) ) ) {
			}
			ngui::seperate_column( 190, 0 );
			if ( ngui::child( "group2", ngui::vec2( 185, 215 ) ) ) {
			}
		}
		ngui::end_window( );
	}
}
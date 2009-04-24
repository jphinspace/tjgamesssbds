void initMinimap(int selStage) {
	PA_ResetBgSysScreen(SUB_SCREEN);

	if(selStage == FINALDESTINATION) {
		PA_EasyBgLoad(SUB_SCREEN, 3, finaldestinationminimap);
	}
	else if(selStage == POKEMONSTADIUM) {
		PA_EasyBgLoad(SUB_SCREEN, 3, pokemonstadiumminimap);
	}
//	else if(selStage == CORNERIA) {
//		PA_EasyBgLoad(SUB_SCREEN, 3, corneria);
//	}
//	else if(selStage == CASTLESIEGE) {
//		PA_EasyBgLoad(SUB_SCREEN, 3, castlesiege);
//	}

	PA_LoadSpritePal(SUB_SCREEN, 1, (void*)charminis_Pal);
	for(int n = 0; n < (int)players.size(); n++) {
		PA_CreateSprite(SUB_SCREEN, n+1, (void*)charminis, OBJ_SIZE_16X16, COLOR256, 1, -16, -16);
		if(players[n] -> name == "kirby") PA_StartSpriteAnimEx(SUB_SCREEN, n+1, KIRBY, KIRBY, 1, ANIM_LOOP, -1);
		else if(players[n] -> name == "mewtwo") PA_StartSpriteAnimEx(SUB_SCREEN, n+1, MEWTWO, MEWTWO, 1, ANIM_LOOP, -1);
		else if(players[n] -> name == "mario") PA_StartSpriteAnimEx(SUB_SCREEN, n+1, MARIO, MARIO, 1, ANIM_LOOP, -1);
		else if(players[n] -> name == "ike") PA_StartSpriteAnimEx(SUB_SCREEN, n+1, IKE, IKE, 1, ANIM_LOOP, -1);
	}
	PA_LoadSpritePal(SUB_SCREEN, 0, (void*)visibleminimap_Pal);
	PA_CreateSprite(SUB_SCREEN, 0, (void*)visibleminimap_Sprite, OBJ_SIZE_64X64, COLOR256, 0, -64, -64);
	// loads the sprite icons for the minimap
} // initializes the minimap display on the sub screen
void displayMinimap() {
	for(int n = 0; n < (int)players.size(); n++) {
		PA_SetSpriteXY(SUB_SCREEN, n+1, (int)((players[n] -> x)/4) + 64, (int)((players[n] -> y)/4) + 32 + 56 + 4);
	}
	// displays the sprites in the correct position on a scaled down map
	PA_SetSpriteXY(SUB_SCREEN, 0, (int)(scrollx/4) + 64, (int)(scrolly/4) + 24 + 56 + 4);
	// displays a box representing the current screen
} // displays the minimap
void displayPercentages() {
	PA_OutputText(SUB_SCREEN, 0, 0, "                                           ");
	PA_OutputText(SUB_SCREEN, 0, 23, "                                           ");
	// clears the text
	if(players.size() >=1) {
		PA_SetTextTileCol(SUB_SCREEN, TEXT_RED);
		int damage = (int)(players[0]->getDamagePercent());
		PA_OutputText(SUB_SCREEN, 0, 0, "%d %", damage);
	} // displays damage percent of player 1
	if(players.size() >= 2) {
		PA_SetTextTileCol(SUB_SCREEN, TEXT_BLUE);
		int damage = (int)(players[1]->getDamagePercent());
		stringstream ss;
		ss << damage;
		int length = ss.str().size();
		PA_OutputText(SUB_SCREEN, 30-length, 0, "%d %", damage);
	} // displays damage percent of player 2
	if(players.size() >= 3) {
		PA_SetTextTileCol(SUB_SCREEN, TEXT_YELLOW);
		int damage = (int)(players[2]->getDamagePercent());
		PA_OutputText(SUB_SCREEN, 0, 23, "%d %", damage);
	} // damage of player 3
	if(players.size() >= 4) {
		PA_SetTextTileCol(SUB_SCREEN, TEXT_GREEN);
		int damage = (int)(players[3]->getDamagePercent());
		stringstream ss;
		ss << damage;
		int length = ss.str().size();
		PA_OutputText(SUB_SCREEN, 30-length, 23, "%d %", damage);
	}
} // displays damage percents on the sub screen
void displayLives(int stock) {
	PA_OutputText(SUB_SCREEN, 0, 1, "                                               ");
	PA_OutputText(SUB_SCREEN, 0, 22, "                                               ");
	if(players.size() >= 1) {
		PA_SetTextTileCol(SUB_SCREEN, TEXT_RED);
		int lives = stock - score.getDeaths(0) - sdcost*score.getSDs(0);
		PA_OutputText(SUB_SCREEN, 0, 1, "x%d", lives);
	}
	if(players.size() >= 2) {
		PA_SetTextTileCol(SUB_SCREEN, TEXT_BLUE);
		int lives = stock-score.getDeaths(1) - sdcost*score.getSDs(1);
		stringstream ss;
		ss << lives;
		int length = ss.str().size();
		PA_OutputText(SUB_SCREEN, 31-length, 1, "x%d", lives);
	}
	if(players.size() >= 3) {
		PA_SetTextTileCol(SUB_SCREEN, TEXT_YELLOW);
		int lives = stock-score.getDeaths(2) - sdcost*score.getSDs(2);
		PA_OutputText(SUB_SCREEN, 0, 22, "x%d", lives);
	}
	if(players.size() >= 4) {
		PA_SetTextTileCol(SUB_SCREEN, TEXT_GREEN);
		int lives = stock-score.getDeaths(3) - sdcost*score.getSDs(3);
		stringstream ss;
		ss << lives;
		int length = ss.str().size();
		PA_OutputText(SUB_SCREEN, 31-length, 22, "x%d", lives);
	}
}

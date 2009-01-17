class Mewtwo: public Fighter {
	public:
		int shadowballcharge;
	// constructor
		Mewtwo(int xpos, int ypos, int num, bool AI = false) {
			x = xpos;
			y = ypos;
			hangtime = 0;
			ledgewait = 0;
			handx = 8;
			handy = 12;
			shadowballcharge = 0;
			CAPE = false;
			COUNTER = false;
			effectwait = 0;
			MYCHAR = MEWTWO;
			chargecount = 0;
			isCPU = AI;
			lasthitby = -1;
			topside = 8;
			bottomside = 52;
			rightside = 44;
			leftside = 22;
			SPRITENUM = num + 100;
			gravity = 3;
			jumpmax = 2;
			charnum = players.size();
			startx = x;
			starty = y;
			action = "fall";
			aerial = true;
			delay = jumpcount = startlag = landinglag = tiltlag = airlag = lcancel = hitstun = 0;
			dx = dy = fastfall = DI = 0.0;
			percentage = 0;
			ymomentum = 0.0;
			momentumtime = 0;
			grabtimeleft = 0;
			name = "mewtwo";
			initSprite();
			initDefbox();
			initAtkbox();
			initFrames();
			if(x > stage.width/2) setDirection("right");
			else setDirection("left");
		} // initializes all of the variables
	// initializers
		void playsound(int sndnum) {}
		void initFrames() {
			// LAND
			startframes.push_back(0);
			endframes.push_back(0);
			framespeeds.push_back(10);

			// SHIELD
			startframes.push_back(114);
			endframes.push_back(114);
			framespeeds.push_back(20);

			// ROLL
			startframes.push_back(110);
			endframes.push_back(113);
			framespeeds.push_back(20);

			// DODGE
			startframes.push_back(114);
			endframes.push_back(118);
			framespeeds.push_back(10);

			// AIRDODGE
			startframes.push_back(119);
			endframes.push_back(125);
			framespeeds.push_back(30);

			// CROUCH
			startframes.push_back(0);
			endframes.push_back(0);
			framespeeds.push_back(20);

			// FALL
			startframes.push_back(28);
			endframes.push_back(28);
			framespeeds.push_back(20);

			// IDLE
			startframes.push_back(1);
			endframes.push_back(6);
			framespeeds.push_back(5);

			// RUN
			startframes.push_back(7);
			endframes.push_back(12);
			framespeeds.push_back(20);

			// SHORTHOP
			startframes.push_back(13);
			endframes.push_back(20);
			framespeeds.push_back(20);

			// JUMP
			startframes.push_back(13);
			endframes.push_back(20);
			framespeeds.push_back(20);

			// DOUBLEJUMP
			startframes.push_back(21);
			endframes.push_back(21);
			framespeeds.push_back(3);

			// JAB
			startframes.push_back(30);
			endframes.push_back(33);
			framespeeds.push_back(10);

			// DASHATTACK
			startframes.push_back(34);
			endframes.push_back(38);
			framespeeds.push_back(10);

			// FTILT
			startframes.push_back(107);
			endframes.push_back(109);
			framespeeds.push_back(6);

			// UTILT
			startframes.push_back(104);
			endframes.push_back(107);
			framespeeds.push_back(6);

			// DTILT
			startframes.push_back(66);
			endframes.push_back(71);
			framespeeds.push_back(10);

			// CHARGELEFT
			startframes.push_back(39);
			endframes.push_back(40);
			framespeeds.push_back(20);

			// CHARGERIGHT
			startframes.push_back(39);
			endframes.push_back(40);
			framespeeds.push_back(20);

			// CHARGEUP
			startframes.push_back(47);
			endframes.push_back(48);
			framespeeds.push_back(20);

			// CHARGEDOWN
			startframes.push_back(58);
			endframes.push_back(59);
			framespeeds.push_back(20);

			// SMASHLEFT
			startframes.push_back(41);
			endframes.push_back(46);
			framespeeds.push_back(20);

			// SMASHRIGHT
			startframes.push_back(41);
			endframes.push_back(46);
			framespeeds.push_back(20);

			// SMASHUP
			startframes.push_back(49);
			endframes.push_back(57);
			framespeeds.push_back(12);

			// SMASHDOWN
			startframes.push_back(60);
			endframes.push_back(65);
			framespeeds.push_back(10);

			// FAIR
			startframes.push_back(80);
			endframes.push_back(85);
			framespeeds.push_back(10);

			// BAIR
			startframes.push_back(87);
			endframes.push_back(92);
			framespeeds.push_back(10);

			// UAIR
			startframes.push_back(98);
			endframes.push_back(102);
			framespeeds.push_back(10);

			// DAIR
			startframes.push_back(93);
			endframes.push_back(97);
			framespeeds.push_back(10);

			// NAIR
			startframes.push_back(72);
			endframes.push_back(79);
			framespeeds.push_back(10);

			// STUN
			startframes.push_back(116);
			endframes.push_back(116);
			framespeeds.push_back(20);

			// SLIDE
			startframes.push_back(0);
			endframes.push_back(0);
			framespeeds.push_back(20);
		
			// HANG
			startframes.push_back(81);
			endframes.push_back(81);
			framespeeds.push_back(20);
			
			// GRABBED
			startframes.push_back(17);
			endframes.push_back(17);
			framespeeds.push_back(20);
						
			// GRAB
			startframes.push_back(146);
			endframes.push_back(146);
			framespeeds.push_back(10);
						
			// GRABATK
			startframes.push_back(45);
			endframes.push_back(45);
			framespeeds.push_back(10);
						
			// FTHROW
			startframes.push_back(150);
			endframes.push_back(154);
			framespeeds.push_back(15);
						
			// BTHROW
			startframes.push_back(148);
			endframes.push_back(149);
			framespeeds.push_back(10);
						
			// UTHROW
			startframes.push_back(147);
			endframes.push_back(147);
			framespeeds.push_back(5);
						
			// DTHROW
			startframes.push_back(155);
			endframes.push_back(157);
			framespeeds.push_back(15);
						
			// DEAD
			startframes.push_back(158);
			endframes.push_back(158);
			framespeeds.push_back(20);
		}
	// actions
		void bside() {
			if(action != "bside") {
				PA_StartSpriteAnimEx(MAIN_SCREEN, SPRITENUM, 135, 136, 10, ANIM_LOOP, -1);
				delay = 60/10 * 2;
				setDirection();
				dx = 0;
				action = "bside";
			}
			else if((PA_GetSpriteAnimFrame(MAIN_SCREEN, SPRITENUM) == 141 || PA_GetSpriteAnimFrame(MAIN_SCREEN, SPRITENUM) == 136) && delay == 1) {
				PA_StartSpriteAnimEx(MAIN_SCREEN, SPRITENUM, 137, 141, 10, ANIM_LOOP, -1);
				delay = 60/10 * 5;
			}
			else if(Pad.Released.B) {
				if(checkFloorCollision()) idle();
				else fall();
			}
		}
		void bup() {
			if(action != "bup") {
				PA_StartSpriteAnimEx(MAIN_SCREEN, SPRITENUM, 119, 122, 10, ANIM_ONESHOT);
				aerial = true;
				delay = 60/10 * 4;
				dy = 0;
				dx = 0;
				DI = 0;
				fastfall = 0;
				action = "bup";
				setDirection();
			}
			else if(action == "bup" && PA_GetSpriteAnimFrame(MAIN_SCREEN, SPRITENUM) == 122 && delay == 1) {
				PA_StartSpriteAnimEx(MAIN_SCREEN, SPRITENUM, 122, 125, 10, ANIM_ONESHOT);
				aerial = true;
				delay = 60/10 * 4;
				y += -200;
			}
			else if(action == "bup" && PA_GetSpriteAnimFrame(MAIN_SCREEN, SPRITENUM) == 125 && delay == 1) {
				if(!checkFloorCollision()) fall();
				else idle();
			}
		}
		void bdown() {
			if(action != "bdown" || (Pad.Held.B && delay == 1)) {
				PA_StartSpriteAnimEx(MAIN_SCREEN, SPRITENUM, 143, 145, 10, ANIM_LOOP, -1);
				delay = 60/10 * 3;
				if(aerial) dy = -gravity/2;
				dx = 0;
				action = "bdown";
			}
			else if(!Pad.Held.B) {
				if(checkFloorCollision()) idle();
				else fall();
			}
			else if(aerial && checkFloorCollision()) dy = 0;
		}
		void bneut() {
			if(action != "bneut") {
				if(shadowballcharge < 40) {
					PA_StartSpriteAnimEx(MAIN_SCREEN, SPRITENUM, 126, 127, 15, ANIM_LOOP, -1);
					delay = 60/15 * 2 * 5;
					dx = 0;
					action = "bneut";				
				}
				else if(shadowballcharge < 80) {
					PA_StartSpriteAnimEx(MAIN_SCREEN, SPRITENUM, 128, 129, 15, ANIM_LOOP, -1);
					delay = 60/15 * 2 * 5;
					dx = 0;
					action = "bneut";
				}
				else if(shadowballcharge < 120) {
					PA_StartSpriteAnimEx(MAIN_SCREEN, SPRITENUM, 130, 131, 15, ANIM_LOOP, -1);
					delay = 60/15 * 2 * 5;
					dx = 0;
					action = "bneut";
				}
				else if(shadowballcharge == 120) {
					PA_StartSpriteAnimEx(MAIN_SCREEN, SPRITENUM, 132, 134, 15, ANIM_LOOP, -1);
					delay = 60/15 * 3;
#ifdef PROJECTILES_ON
					int SHADOWBALL_SIZE = -1;
					int directionmodifier = 1;
					if(direction == "right") directionmodifier = -1;
					Hitbox tempbox;
					tempbox.addCircle(createAtkbox(32, 32, 14, Knockback(-3*directionmodifier, -1.5, 8), 240));
					projectiles.push_back(Projectile(x, y, -3*directionmodifier, 0, 100, SHADOWBALL_LARGE, charnum, tempbox, stage));
#endif
					shadowballcharge = 0;
					action = "bneut";
					dx = 0;
				}
			}
			else if(Pad.Newpress.B) {
				PA_StartSpriteAnimEx(MAIN_SCREEN, SPRITENUM, 132, 134, 15, ANIM_LOOP, -1);
				delay = 60/15 * 3;
#ifdef PROJECTILES_ON
				int SHADOWBALL_SIZE = -1;
				if(shadowballcharge >= 80) SHADOWBALL_SIZE = SHADOWBALL_LARGE;
				else if(shadowballcharge >= 40) SHADOWBALL_SIZE = SHADOWBALL_MEDIUM;
				else SHADOWBALL_SIZE = SHADOWBALL_SMALL;
				int directionmodifier = 1;
				if(direction == "right") directionmodifier = -1;
				Hitbox tempbox;
				int rad = 0;
				double kbmod = 1;
				if(SHADOWBALL_SIZE == SHADOWBALL_LARGE) {
					rad = 14;
					kbmod = 1;
				}
				else if(SHADOWBALL_SIZE == SHADOWBALL_MEDIUM) {
					rad = 10;
					kbmod = 1.5;
				}
				else {
					rad = 8;
					kbmod = 3;
				}
//				tempbox.addCircle(createAtkbox(32, 32, rad, Knockback((-3*directionmodifier/kbmod), -1.5/kbmod, 8), shadowballcharge*2));
				tempbox.addCircle(createAtkbox(32, 32, rad, Knockback((-3*directionmodifier), -1.5, 8), 120));
				projectiles.push_back(Projectile(x, y, -3*directionmodifier, 0, 100, SHADOWBALL_SIZE, charnum, tempbox, stage));
#endif
				shadowballcharge = 0;
			}
			else if(PA_GetSpriteAnimFrame(MAIN_SCREEN, SPRITENUM) == 132) {}
			else if(PA_GetSpriteAnimFrame(MAIN_SCREEN, SPRITENUM) == 133) {}
			else if(PA_GetSpriteAnimFrame(MAIN_SCREEN, SPRITENUM) == 134) {
				if(delay == 1) {
					if(checkFloorCollision()) idle();
					else fall();
				}
			}
			else if(Pad.Newpress.R || Pad.Newpress.L) shield();
			else {
				shadowballcharge+=1;
				if(shadowballcharge > 120) shadowballcharge = 120;
				if(delay == 1 && PA_GetSpriteAnimFrame(MAIN_SCREEN, SPRITENUM) == 127) {
					PA_StartSpriteAnimEx(MAIN_SCREEN, SPRITENUM, 128, 129, 15, ANIM_LOOP, -1);
					delay = 60/15 * 2 * 5;
				}
				else if(delay == 1 && (PA_GetSpriteAnimFrame(MAIN_SCREEN, SPRITENUM) == 129 || PA_GetSpriteAnimFrame(MAIN_SCREEN, SPRITENUM) == 131)) {
					PA_StartSpriteAnimEx(MAIN_SCREEN, SPRITENUM, 130, 131, 15, ANIM_LOOP, -1);
					delay = 60/15 * 2 * 5;
				}				
			}
		}
		void jaywalk() {}
};

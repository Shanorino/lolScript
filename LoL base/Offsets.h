#pragma once
#define TARGET_GAMEVERSION "Version 10.16.330.9186 [PUBLIC]"  // 

#define oNetClient 0x3506864 // 												8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B	
#define oChatClientPtr 0x02f79384 //												8B 0D ? ? ? ? 0F 43 44 24 ? 52 50 E8 ? ? ? ? E8 
#define oObjManager 0x016dc5f4 //												8B 0D ? ? ? ? E8 ? ? ? ? FF 77						//
#define oZoomClass 0x34F7218 //													A3 ? ? ? ? 83 FA 10 72 32							//
#define oGameInfo 0x34F89C4 // 													A1 ? ? ? ? 83 78 08 02 0F 94 C0
#define oHudInstance 0x1C5CC6C ///										8B 0D ? ? ? ? 6A 00 8B 49 34 E8 ? ? ? ? B0         //
#define oRenderer 0x2F9E33C // 													8B 15 ? ? ? ? 83 EC 08 F3
#define oUnderMouseObject 0x232A7C0 // 											C7 05 ? ? ? ? ? ? ? ? E8 ? ? ? ? 68 ? ? ? ? E8 ? ? ? ? 83 C4 08 EB AD 11.5
#define oD3DRenderer 0x2F9E33C // 												A1 ? ? ? ? 89 54 24 18 
#define oWorldToScreen 0x2F9B4E0 // 	not sure											83 EC 10 56 E8 ? ? ? ? 8B 08 
#define oLocalPlayer 0x02f792b8 //												A1 ?? ?? ?? ?? 85 C0 74 07 05 ?? ?? ?? ?? EB 02 33 C0 56  //
#define oGameTime 0x02f71134 // 													F3 0F 11 05 ? ? ? ? 8B 49							//
#define oGetFirstObject 0x2BBAF0    //8B 41 14 8B 51 18
#define oGetNextObject 0x2BCCA0    //E8 ? ? ? ? 8B F0 85 F6 75 E4
#define oGameVersion 0x57FB60     //												8B 44 24 04 BA ? ? ? ? 2B D0						//
// FUNCTIONS
#define oCastSpell 0x4D7F20
#define oDrawCircle 0x50E1F0 
#define oGetBasicAttack 0x1774A0 
#define oGetAttackCastDelay 0x2B6360 
#define oGetAttackDelay 0x2B6460 
#define oGetPing 0x343DC0// 													E8 ? ? ? ? 8B 4F 2C 85 C9 0F
#define oPingInstance 0x3506864 //												8B 0D ? ? ? ? 85 C9 74 07 8B 01 6A 01 FF 50 08 8B
#define oGetSpellState 0x50A570 // 												E8 ? ? ? ? 8B F8 8B CB 89  						//	
#define oIsTargetable 0x1EEFF0 //												56 8B F1 E8 ? ? ? ? 84 C0 74 2E 
#define oIsAlive 0x1B75C0 // 													56 8B F1 8B 06 8B 80 ? ? ? ? FF D0 84 C0 74 19		//
#define oIsBaron 0x18B0A0 //													56 E8 ? ? ? ? 68 ? ? ? ? 8B 30 
#define oIsTurret 0x1CB4D0 // 													E8 ? ? ? ? 83 C4 04 84 C0 74 09 5F					//
#define oIsInhib 0x1CB160 // 													E8 ? ? ? ? 83 C4 04 84 C0 74 38					//
#define oIsHero 0x1CB2E0 // 													E8 ? ? ? ? 83 C4 04 84 C0 74 2B 57				//
#define oIsMinion 0x1CB320 // 													E8 ? ? ? ? 83 C4 04 84 C0 74 4A 8B 45				//
#define oIsDragon 0x188FF0 //  													83 EC 10 A1 ? ? ? ? 33 C4 89 44 24 0C 56 E8		//
#define oIsMissile 0x1CB340 //											   		E8 ? ? ? ? 83 C4 04 84 C0 74 1C FF					//
#define oIsNexus 0x1CB260 //													E8 ? ? ? ? 83 C4 04 84 C0 0F 95 C0 C3 CC 8A
#define oIsNotWall 0x8E4030 // 													E8 ? ? ? ? 33 C9 83 C4 0C 84						//
#define oIsTroy 0x1CB1E0  //// 
#define oIssueOrder 0x15F2E0 // 												81 EC ? ? ? ? 56 57 8B F9 C7						//
#define oPrintChat 0x57A9D0 //	

//CObject
#define oObjIndex 0x20
#define oObjTeam 0x4C
#define oObjName 0x6C
#define oObjNetworkID 0xCC
#define oObjPos 0x1d8
#define oObjVisibility 0x270
#define oObjHealth 0xD98
#define oObjMana 0x298
#define oObjMaxMana 0x48C 
#define oObjArmor 0x129C
#define oObjMagicRes 0x12A4 
#define oObjBonusMagicRes 0x1490 
#define oObjBaseAtk 0x1274
#define oObjBonusAtk 0x11F0
#define oObjMoveSpeed 0x12B4
#define oObjAtkRange 0x14B4
#define oObjBuffMgr 0x2178
#define oObjSpellBook 0x2720
#define oObjSpellBookSpellSlots 0x478
#define oObjChampionName 0x35BC
#define oObjLevel 0x36D4

//
#define objectArray 0x14
#pragma once
#include <vector>
#include <algorithm>

class GFuncs 
{
public:
	std::vector<CObject*> HeroList;
	std::vector<CObject*> MinionList;
	float myAttack = me->GetBaseAttackDamage() + me->GetBonusAttackDamage();
	
	void setup()
	{
		HeroList.clear();
		MinionList.clear();
		CObject* obj = NULL;
		for (int i = 0; i < 10000; i++)
		{
			obj = Engine::GetObjectByID(i);
			if (obj == NULL) break;

			int team = obj->GetTeam();
			if (team == 100 || team == 200 || team == 300) // 100 and 200 are players. 300 means monsters
			{
				if (obj->IsHero() && obj->IsAlive())
				{
					HeroList.push_back(obj);
				}
				else if (obj->IsMinion() && obj->IsAlive())
				{
					MinionList.push_back(obj);
				}
			}
		}
	}

	CObject* findNearestEnemy(CObject* localObj, std::vector<CObject*> list)
	{
		CObject* nearestObj = NULL;
		float nearestDist = 9999;
		for (std::size_t i = 1; i < list.size(); i++)
		{
			CObject* currObj = list[i];
			// only enemy
			if (!currObj->IsEnemyTo(localObj)) continue;
			// find smallest distance
			float currDistToLObj = localObj->GetPos().DistTo(currObj->GetPos());
			if (currDistToLObj < nearestDist)
			{
				nearestObj = currObj;
			}
		}
		return nearestObj;
	}

	void autoSkillR(char* textFromMenu, bool &reactionFlag, bool &keyFlag, char* autoSkillTimes)
	{
		int healthLimitR = std::atoi(textFromMenu);
		int autoSkill = std::atoi(autoSkillTimes);
		if (autoSkill == 0)
			autoSkill = 1;
		if (me->GetHealth() < healthLimitR && me->GetHealth() > 0 && reactionFlag && keyFlag)
		{
			//Engine::MoveTo(new Vector{ 0, 0, 0});
			for (int i = 0; i < 1; i++)
			{
				keybd_event(VkKeyScan('R'), 0x13, 0, 0); // 'W' Press
				Sleep(50);
				keybd_event(VkKeyScan('R'), 0x13, KEYEVENTF_KEYUP, 0);
			}
			//Functions.CastSpell()
			//Engine::CastSpellSelf(2);
			//Beep(2000, 1000);
			reactionFlag = false;
		}
		else if (me->GetHealth() > healthLimitR && !reactionFlag && keyFlag)
		{ 
			reactionFlag = true;
		}
	}

	void autoRunAndKill()
	{
		// find nearest hero
		CObject* nearestHero = findNearestEnemy(me, HeroList);
		if (nearestHero)
		{
			float distToHero = me->GetPos().DistTo(nearestHero->GetPos());
			if (distToHero < 700)
			{
				Engine::AttackTarget(nearestHero);
			}
		}
	}

	void autoMinionKill()
	{
		for each (CObject* minion in MinionList)
		{
			if (!minion->IsEnemyTo(me)) continue;
			float minionHealth = minion->GetHealth();
			if (minionHealth <= myAttack)
			{
				float distToMinion = me->GetPos().DistTo(minion->GetPos());
				if (distToMinion < 700)
				//if (distToMinion < me->GetAttackRange() + me->GetBoundingRadius())
				{
					Engine::AttackTarget(minion);
				}
			}
		}
	}


};
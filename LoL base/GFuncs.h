#pragma once
#include <vector>

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

	void autoSkillR()
	{
		int healthLimitR = std::atoi(text1);
		if (me->GetHealth() < healthLimitR && low_health_reaction && f_10_flag)
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
			low_health_reaction = false;
		}
		else if (me->GetHealth() > healthLimitR && !low_health_reaction && f_10_flag)
		{ 
			low_health_reaction = true; 
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
#include "Monster.h"
#include "ShootingMap.h"

void Monster::DeadByBullet(ShootingMap& _map, Int4& _pos)
{
	_map.SetTile(Pos, 'D');
}
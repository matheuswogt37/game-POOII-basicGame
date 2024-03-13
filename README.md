# game-POOII-basicGame
c++ project for oriented object programming


diagram yuml

```
[<<Abstract>>Entity]^[Hero]
[<<Abstract>>Entity]^[Monster]
[<<Abstract>>Entity]^[Weapon]
[<<Abstract>>Entity]^[Ring]
[Weapon]^[<<Abstract>>Item]
[Ring]^[<<Abstract>>Item]
[<<Interface>>BattleActions]^[<<Abstract>>Entity]
[Hero]^[Battle]
[Monster]^[Battle]
[Menu]^[Stage]
[Menu]^[Battle]


// calcDamage return damage int; calcGuard return percent damaged 0 - 100
[<<Interface>>BattleActions| | calcDamage(): int; calcGuard(): int]

[<<Abstract>>Entity| name: string; life: int; strength: int; intelligence: int; dexterity: int; damage: int; resistence: int; weapon: Item; ring: Item| calcDamage(): int; calcGuard(): int]

[Hero| score: int]

[Monster| points: int; asciiArt: string; multiplierStatus: double]

[Battle| hero: Hero; monster: Monster]

[<<Abstract>>Item| name: string; type: int; attribute: int; value: int; multStatus: double| showItem(): void; switchItem(): void; ifNUll(): int; getAttribute(): string]

[Weapon| | showItem()]

[Ring| | showItem()]

[Battle| initiative: int; hero: Hero; monster: Monster| attack(): void]

// difficult multiplirItemStatus will be default int 100 - 1 like percent
[Stage| level: int; difficult: int; multiplierItemStatus: int| randomEvent(); randomItem(); randomMonster()]

[Menu| mode: int; stage: Stage; battle: Battle| mBattle(); mIdle(); mChar(); mOptions(); mScore()]
```
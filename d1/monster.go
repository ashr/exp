package d1

import (
	"bytes"
	"encoding/binary"
	"fmt"

	"github.com/pkg/errors"
)

// MonsterData specifies the data related to a monster ID.
type MonsterData struct {
	// Frame width of monster graphics.
	FrameWidth int32
	// Approximate memory usage in KB (e.g. the size of "monsters/zombie/" is
	// ~799 KB).
	MemoryUsage int32
	// CL2 graphics path format string.
	CL2Path string
	// Specifies whether the monster has a special graphic (i.e. monster action
	// "s").
	HasSpecialGraphic bool
	// WAV sound path format string.
	WavPath string
	// Specifies whether the monster has a special sound (i.e. monster action
	// "s").
	HasSpecialSound bool
	// Specifies whether the monster has a colour transition.
	HasTrn bool
	// Colour transition path.
	TrnPath string
	// Map from monster action to number of frames.
	NFrames [6]int32
	// Map from action to animation playback rate.
	Rate [6]int32
	// Monster name.
	Name string
	// Minimum dungeon level at which the monster may be present.
	MinDLvl int8
	// Maximum dungeon level at which the monster may be present.
	MaxDLvl int8
	// Monster level.
	Level int8
	// Minimum health points.
	MinHP int32
	// Maximum health points.
	MaxHP int32
	// Monster AI.
	AI MonsterAI
	// TODO: Define dedicated type for monster flags.

	// Bitfield of monster flags.
	Flags uint32
	// Monster intelligence.
	Intelligence int8
	// Chance to hit.
	ChanceToHit int8
	// Starting frame of attack animation; 1-indexed.
	AttackFrame int8
	// Minimum damage.
	MinDamage int8
	// Maximum damage.
	MaxDamage int8
	// Chance to hit with special attack.
	ChanceToHitSpecial int8
	// Starting frame of attack animation with special attack; 1-indexed.
	AttackFrameSpecial int8
	// Minimum damage with special attack.
	MinDamageSpecial int8
	// Maximum damage with special attack.
	MaxDamageSpecial int8
	// Armor class.
	ArmorClass int8
	// Monster class.
	MonsterClass int8
	// Resistance and immunity bitfield.
	Resistance int16
	// Resistance and immunity bitfield (hell difficulty).
	ResistanceHell int16
	// Treasure dropped by monster.
	Treasure int16
	// TODO: Define dedicated type for monster selection flag.

	// TODO: Figure out what SelFlag represents and document. Monster selection
	// flag?
	SelFlag uint8
	// Experience.
	Exp int16
}

// MonsterAI specifies the set of monster AIs.
type MonsterAI uint8

// Monster AIs.
const (
	MonsterAI_Zombie             MonsterAI = 0
	MonsterAI_Overlord           MonsterAI = 1
	MonsterAI_Skeleton           MonsterAI = 2
	MonsterAI_SkeletonArcher     MonsterAI = 3
	MonsterAI_Scavenger          MonsterAI = 4
	MonsterAI_HornedDemon        MonsterAI = 5
	MonsterAI_GoatMan            MonsterAI = 6
	MonsterAI_GoatManArcher      MonsterAI = 7
	MonsterAI_FallenOne          MonsterAI = 8
	MonsterAI_MagmaDemon         MonsterAI = 9
	MonsterAI_SkeletonKing       MonsterAI = 10
	MonsterAI_WingedFiend        MonsterAI = 11
	MonsterAI_Gargoyle           MonsterAI = 12
	MonsterAI_TheButcher         MonsterAI = 13
	MonsterAI_Succubus           MonsterAI = 14
	MonsterAI_Hidden             MonsterAI = 15
	MonsterAI_LightningDemon     MonsterAI = 16
	MonsterAI_Fireman            MonsterAI = 17
	MonsterAI_GharbadTheWeak     MonsterAI = 18
	MonsterAI_SpittingTerror     MonsterAI = 19
	MonsterAI_FastSpittingTerror MonsterAI = 20
	MonsterAI_Golem              MonsterAI = 21
	MonsterAI_ZharTheMad         MonsterAI = 22
	MonsterAI_Snotspill          MonsterAI = 23
	MonsterAI_Viper              MonsterAI = 24
	MonsterAI_Mage               MonsterAI = 25
	MonsterAI_Balrog             MonsterAI = 26
	MonsterAI_TheDarkLord        MonsterAI = 27
	MonsterAI_ArchBishopLazarus  MonsterAI = 28
	MonsterAI_UniqueSuccubus     MonsterAI = 29 // Red Vex, Blue Jade
	MonsterAI_Lachdanan          MonsterAI = 30
	MonsterAI_WarlordOfBlood     MonsterAI = 31
)

// MonsterAction specifies the set of monster actions.
type MonsterAction uint8

// Monster actions.
const (
	MonsterActionStand   MonsterAction = 0 // monster action "n"
	MonsterActionWalk    MonsterAction = 1 // monster action "w"
	MonsterActionAttack  MonsterAction = 2 // monster action "a"
	MonsterActionHit     MonsterAction = 3 // monster action "h"
	MonsterActionDie     MonsterAction = 4 // monster action "d"
	MonsterActionSpecial MonsterAction = 5 // monster action "s"
)

// String returns the string representation of the monster AI.
func (ai MonsterAI) String() string {
	m := map[MonsterAI]string{
		MonsterAI_Zombie:         "Zombie AI",
		MonsterAI_Overlord:       "Overlord AI",
		MonsterAI_Skeleton:       "Skeleton AI",
		MonsterAI_SkeletonArcher: "Skeleton (archer) AI",
		MonsterAI_Scavenger:      "Scavenger AI",
		MonsterAI_HornedDemon:    "Horned Demon AI",
		// NOTE: name from manual.
		MonsterAI_GoatMan: "Goat Man AI",
		// NOTE: name from manual.
		MonsterAI_GoatManArcher: "Goat Man (archer) AI",
		MonsterAI_FallenOne:     "Fallen One AI",
		MonsterAI_MagmaDemon:    "Magma Demon AI",
		MonsterAI_SkeletonKing:  "Skeleton King AI",
		MonsterAI_WingedFiend:   "Winged Fiend AI",
		MonsterAI_Gargoyle:      "Gargoyle AI",
		MonsterAI_TheButcher:    "The Butcher AI",
		MonsterAI_Succubus:      "Succubus AI",
		MonsterAI_Hidden:        "Hidden AI",
		// TODO: Consider finding a better name; as non of the base monster types is
		// called Lightning Demon, and Lightning Demon is not mentioned in the
		// manual.
		MonsterAI_LightningDemon: "Lightning Demon AI",
		// NOTE: name from CEL graphic.
		MonsterAI_Fireman:        "Fireman AI",
		MonsterAI_GharbadTheWeak: "Gharbad the Weak AI",
		// NOTE: name from manual.
		MonsterAI_SpittingTerror: "Spitting Terror AI",
		// TODO: Check how MonsterAI_SpittingTerror and MonsterAI_SpittingTerrorFast
		// differ, and why MonsterAI_SpittingTerrorFast is named fast.

		// NOTE: name from manual.
		MonsterAI_FastSpittingTerror: "Spitting Terror (fast) AI",
		MonsterAI_Golem:              "Golem AI",
		MonsterAI_ZharTheMad:         "Zhar the Mad AI",
		MonsterAI_Snotspill:          "Snotspill AI",
		MonsterAI_Viper:              "Viper AI",
		// NOTE: name from CEL graphic.
		MonsterAI_Mage:              "Mage AI",
		MonsterAI_Balrog:            "Balrog AI",
		MonsterAI_TheDarkLord:       "The Dark Lord AI",
		MonsterAI_ArchBishopLazarus: "Arch-Bishop Lazarus AI",
		MonsterAI_UniqueSuccubus:    "Succubus (Red Vex, Blue Jade) AI",
		MonsterAI_Lachdanan:         "Lachdanan AI",
		MonsterAI_WarlordOfBlood:    "Warlord of Blood AI",
	}
	if s, ok := m[ai]; ok {
		return s
	}
	return fmt.Sprintf("unknown monster AI %d", uint8(ai))
}

// --- [ parsing ] -------------------------------------------------------------

// ref: version 1.09b.
const (
	monsterDataAddr  = 0x497E08
	monsterDataElems = 112
)

// monsterData specifies the data related to a monster ID.
//
// PSX def:
//
//    typedef struct MonsterData {
//       unsigned short GraphicType;
//       unsigned char has_special;
//       unsigned short sndfile;
//       unsigned char snd_special;
//       char TransFile;
//       char Frames[6];
//       char Rate[6];
//       int mName;
//       char mMinDLvl;
//       char mMaxDLvl;
//       char mLevel;
//       short mMinHP;
//       short mMaxHP;
//       unsigned char mAi;
//       unsigned short mFlags;
//       unsigned char mInt;
//       unsigned char mHit;
//       unsigned char mAFNum;
//       unsigned char mMinDamage;
//       unsigned char mMaxDamage;
//       unsigned char mHit2;
//       unsigned char mAFNum2;
//       unsigned char mMinDamage2;
//       unsigned char mMaxDamage2;
//       char mArmorClass;
//       char mMonstClass;
//       unsigned short mMagicRes;
//       unsigned short mMagicRes2;
//       unsigned short mTreasure;
//       char mSelFlag;
//       unsigned short mExp;
//    } MonsterData;
type monsterData struct {
	// Frame width of monster graphics.
	//
	// offset 0000 (4 bytes)
	FrameWidth int32
	// Approximate memory usage in KB (e.g. the size of "monsters/zombie/" is
	// ~799 KB).
	//
	// offset 0004 (4 bytes)
	MemoryUsage int32
	// CL2 graphics path format string; address to NULL-terminated string.
	//
	// offset 0008 (4 bytes)
	CL2Path uint32
	// Specifies whether the monster has a special graphic (i.e. monster action
	// "s"); boolean value.
	//
	// offset 000C (4 bytes)
	HasSpecialGraphic uint32
	// WAV sound path format string; address to NULL-terminated string.
	//
	// offset 0010 (4 bytes)
	WavPath uint32
	// Specifies whether the monster has a special sound (i.e. monster action
	// "s"); boolean value.
	//
	// offset 0014 (4 bytes)
	HasSpecialSound uint32
	// Specifies whether the monster has a colour transition; boolean value.
	//
	// offset 0018 (4 bytes)
	HasTrn uint32
	// Colour transition path; address to NULL-terminated string.
	//
	// offset 001C (4 bytes)
	TrnPath uint32
	// Map from monster action to number of frames.
	//
	// offset 0020 (24 bytes)
	NFrames [6]int32
	// TODO: Figure out how playback rate work.

	// Map from action to animation playback rate.
	//
	// offset 0038 (24 bytes)
	Rate [6]int32
	// Monster name; address to NULL-terminated string.
	//
	// offset 0050 (4 bytes)
	Name uint32
	// TODO: Figure out if it is dungeon level or monster/quality level that
	// these two values specify.

	// Minimum dungeon level at which the monster may be present.
	//
	// offset 0054 (1 byte)
	MinDLvl int8
	// Maximum dungeon level at which the monster may be present.
	//
	// offset 0055 (1 byte)
	MaxDLvl int8
	// TODO: Figure out what monster level specifies.
	//
	// Note, MinDLvl <= MonsterLvl <= MaxDLvl holds true for all monsters except:
	//    "Illusion Weaver"
	//    "Lord Sayter"
	//    "Skeleton King"
	//    "The Butcher"
	//    "Magma Demon"
	//    "Blood Stone"
	//    "Devil Kin Brute"
	//    "Death Wing"
	//    "Azure Drake"
	//    "Blood Knight"
	//    "Unraveler"
	//    "Hollow One"
	//    "Golem"
	//    "The Dark Lord"

	// Monster level.
	//
	// offset 0056 (1 byte)
	Level int8
	// Padding.
	//
	// offset 0057 (1 byte)
	_ int8
	// Minimum health points.
	//
	// offset 0058 (4 bytes)
	MinHP int32
	// Maximum health points.
	//
	// offset 005C (4 bytes)
	MaxHP int32
	// Monster AI.
	//
	// offset 0060 (1 byte)
	AI uint8
	// Padding.
	//
	// offset 0061 (3 bytes)
	_ [3]byte
	// Bitfield of monster flags.
	//
	// offset 0064 (4 bytes)
	Flags uint32
	// Monster intelligence.
	//
	// offset 0068 (1 byte)
	Intelligence int8
	// Chance to hit.
	//
	// offset 0069 (1 byte)
	ChanceToHit int8
	// TODO: Figure out how AttackFrame and AttackFrameSpecial works, and if they
	// specify the starting attack frame or hit frame.

	// Starting frame of attack animation; 1-indexed.
	//
	// offset 006A (1 byte)
	AttackFrame int8
	// Minimum damage.
	//
	// offset 006B (1 byte)
	MinDamage int8
	// Maximum damage.
	//
	// offset 006C (1 byte)
	MaxDamage int8
	// Chance to hit with special attack.
	//
	// offset 006D (1 byte)
	ChanceToHitSpecial int8
	// Starting frame of attack animation with special attack; 1-indexed.
	//
	// offset 006E (1 byte)
	AttackFrameSpecial int8
	// Minimum damage with special attack.
	//
	// offset 006F (1 byte)
	MinDamageSpecial int8
	// Maximum damage with special attack.
	//
	// offset 0070 (1 byte)
	MaxDamageSpecial int8
	// Armor class.
	//
	// offset 0071 (1 byte)
	ArmorClass int8
	// TODO: Figure out how monster class works.

	// Monster class.
	//
	// offset 0072 (1 byte)
	MonsterClass int8
	// Padding.
	//
	// offset 0073 (1 byte)
	_ int8
	// TODO: Verify that ResistanceHell is actually and only used for hell
	// difficulty.

	// Resistance and immunity bitfield.
	//
	// offset 0074 (2 bytes)
	Resistance int16
	// Resistance and immunity bitfield (hell difficulty).
	//
	// offset 0076 (2 bytes)
	ResistanceHell int16
	// Treasure dropped by monster.
	//
	// offset 0078 (2 bytes)
	Treasure int16
	// TODO: Figure out what SelFlag does and document.

	// TODO: Document.
	//
	// offset 007A (1 byte)
	SelFlag uint8
	// Padding.
	//
	// offset 007B (1 byte)
	_ int8
	// Experience.
	//
	// offset 007C (2 bytes)
	Exp int16
	// Padding.
	//
	// offset 007E (2 bytes)
	_ [2]byte
}

// parseMonsterData parses the monster data contained within the executable.
func (exe *Executable) parseMonsterData() error {
	data := exe.file.Data(monsterDataAddr)
	monsters := make([]monsterData, monsterDataElems)
	r := bytes.NewReader(data)
	if err := binary.Read(r, binary.LittleEndian, &monsters); err != nil {
		return errors.WithStack(err)
	}
	for _, monster := range monsters {
		exe.Monsters = append(exe.Monsters, exe.translateMonsterData(monster))
	}
	return nil
}

// translateMonsterData translates the binary representation of the MonsterData
// struct to an equivalent version in Go.
func (exe *Executable) translateMonsterData(old monsterData) MonsterData {
	monster := MonsterData{
		FrameWidth:         old.FrameWidth,
		MemoryUsage:        old.MemoryUsage,
		CL2Path:            exe.parseString(old.CL2Path),
		HasSpecialGraphic:  translateBool32(old.HasSpecialGraphic),
		WavPath:            exe.parseString(old.WavPath),
		HasSpecialSound:    translateBool32(old.HasSpecialSound),
		HasTrn:             translateBool32(old.HasTrn),
		TrnPath:            exe.parseString(old.TrnPath),
		NFrames:            old.NFrames,
		Rate:               old.Rate,
		Name:               exe.parseString(old.Name),
		MinDLvl:            old.MinDLvl,
		MaxDLvl:            old.MaxDLvl,
		Level:              old.Level,
		MinHP:              old.MinHP,
		MaxHP:              old.MaxHP,
		AI:                 MonsterAI(old.AI),
		Flags:              old.Flags,
		Intelligence:       old.Intelligence,
		ChanceToHit:        old.ChanceToHit,
		AttackFrame:        old.AttackFrame,
		MinDamage:          old.MinDamage,
		MaxDamage:          old.MaxDamage,
		ChanceToHitSpecial: old.ChanceToHitSpecial,
		AttackFrameSpecial: old.AttackFrameSpecial,
		MinDamageSpecial:   old.MinDamageSpecial,
		MaxDamageSpecial:   old.MaxDamageSpecial,
		ArmorClass:         old.ArmorClass,
		MonsterClass:       old.MonsterClass,
		Resistance:         old.Resistance,
		ResistanceHell:     old.ResistanceHell,
		Treasure:           old.Treasure,
		SelFlag:            old.SelFlag,
		Exp:                old.Exp,
	}
	return monster
}

// translateMonsterAI translates the binary representation of the MonsterData
// struct to an equivalent version in Go.
func translateMonsterAI(ai uint8) MonsterAI {
	i := MonsterAI(ai)
	if MonsterAI_Zombie <= i && i <= MonsterAI_WarlordOfBlood {
		return i
	}
	panic(fmt.Errorf("support for monster AI %d not yet implemented", uint8(i)))
}

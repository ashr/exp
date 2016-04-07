package main

import (
	"fmt"
	"log"
)

// fixDupFiles fixes duplicates source files by adding numeric suffixes.
func fixDupFiles(sectName string, files []*SourceFile) {
	// Record the number of occurances of each source file.
	count := make(map[string]int)
	for _, file := range files {
		count[file.Name]++
	}

	// Add counter for duplicate files, starting at 1. The counter represents the
	// suffix and is incremented with each occurance of a given file name.
	m := make(map[string]int)
	for _, file := range files {
		if count[file.Name] > 1 {
			m[file.Name] = 1
		}
	}
	for _, file := range files {
		if n := m[file.Name]; n != 0 {
			m[file.Name]++
			if verbose {
				log.Printf(`Duplicate %q source file in section %q; adding "_%d" suffix.`, file.Name, sectName, n)
			}
			file.Name = fmt.Sprintf("%s_%d", file.Name, n)
		}
	}
}

// SourceFile maps between address ranges and source code file names.
type SourceFile struct {
	// File name without extension.
	Name string
	// Start address; inclusive.
	Start uint64
	// End address; exclusive.
	End uint64
	// Declarations.
	Decls []Decl
}

// ref: https://github.com/sanctuary/notes/blob/master/functions/README.md
var textFiles = []*SourceFile{
	{Name: "_crt", Start: 0x401000, End: 0x40102A},
	{Name: "appfat", Start: 0x40102A, End: 0x401DA4},
	{Name: "automap", Start: 0x401DA4, End: 0x40311B},
	{Name: "capture", Start: 0x40311B, End: 0x4034D9},
	{Name: "codec", Start: 0x4034D9, End: 0x4037D4},
	{Name: "control", Start: 0x4037D4, End: 0x40740A},
	{Name: "cursor", Start: 0x40740A, End: 0x4084A6},
	{Name: "dead", Start: 0x4084A6, End: 0x4086F4},
	{Name: "debug", Start: 0x4086F4, End: 0x4087B1},
	{Name: "diablo", Start: 0x4087B1, End: 0x40ACAD},
	{Name: "doom", Start: 0x40ACAD, End: 0x40ADD6},
	{Name: "drlg_l1", Start: 0x40ADD6, End: 0x40D357},
	{Name: "drlg_l2", Start: 0x40D357, End: 0x40FF81},
	{Name: "drlg_l3", Start: 0x40FF81, End: 0x412655},
	{Name: "drlg_l4", Start: 0x412655, End: 0x415098},
	{Name: "dthread", Start: 0x415098, End: 0x415362},
	{Name: "dx", Start: 0x415362, End: 0x4158A9},
	{Name: "effects", Start: 0x4158A9, End: 0x415F43},
	{Name: "encrypt", Start: 0x415F43, End: 0x4161FC},
	{Name: "engine", Start: 0x4161FC, End: 0x41804E},
	{Name: "error", Start: 0x41804E, End: 0x4182AD},
	{Name: "exception", Start: 0x4182AD, End: 0x418866},
	{Name: "gamemenu", Start: 0x418866, End: 0x418C8B},
	{Name: "gendung", Start: 0x418C8B, End: 0x419E8B},
	{Name: "gmenu", Start: 0x419E8B, End: 0x41A553},
	{Name: "help", Start: 0x41A553, End: 0x41A7B3},
	{Name: "init", Start: 0x41A7B3, End: 0x41B190},
	{Name: "interfac", Start: 0x41B190, End: 0x41B814},
	{Name: "inv", Start: 0x41B814, End: 0x41F096},
	{Name: "items", Start: 0x41F096, End: 0x425443},
	{Name: "lighting", Start: 0x425443, End: 0x426564},
	{Name: "loadsave", Start: 0x426564, End: 0x4279F2},
	{Name: "log", Start: 0x4279F2, End: 0x427E0E},
	{Name: "mainmenu", Start: 0x427E0E, End: 0x428056},
	{Name: "minitext", Start: 0x428056, End: 0x4283C0},
	{Name: "missiles", Start: 0x4283C0, End: 0x430FDF},
	{Name: "monster", Start: 0x430FDF, End: 0x43AD33},
	{Name: "movie", Start: 0x43AD33, End: 0x43AE90},
	{Name: "mpqapi", Start: 0x43AE90, End: 0x43BBA4},
	{Name: "msg", Start: 0x43BBA4, End: 0x43F849},
	{Name: "msgcmd", Start: 0x43F849, End: 0x43FAC4},
	{Name: "multi", Start: 0x43FAC4, End: 0x440DAE},
	{Name: "nthread", Start: 0x440DAE, End: 0x44121D},
	{Name: "objects", Start: 0x44121D, End: 0x448755},
	{Name: "hero", Start: 0x448755, End: 0x448DF5},
	{Name: "palette", Start: 0x448DF5, End: 0x4493D4},
	{Name: "path", Start: 0x4493D4, End: 0x4498EC},
	{Name: "pfile", Start: 0x4498EC, End: 0x44A8E6},
	{Name: "player", Start: 0x44A8E6, End: 0x450D33},
	{Name: "plrmsg", Start: 0x450D33, End: 0x450FFE},
	{Name: "portal", Start: 0x450FFE, End: 0x45138E},
	{Name: "quests", Start: 0x45138E, End: 0x452831},
	{Name: "restricted", Start: 0x452831, End: 0x452975},
	{Name: "scrollrt", Start: 0x452975, End: 0x456625},
	{Name: "setmaps", Start: 0x456625, End: 0x456A16},
	{Name: "sha1", Start: 0x456A16, End: 0x456CBB},
	{Name: "sound", Start: 0x456CBB, End: 0x45744E},
	{Name: "spell", Start: 0x45744E, End: 0x457A01},
	{Name: "stores", Start: 0x457A01, End: 0x45C199},
	{Name: "sync", Start: 0x45C199, End: 0x45C870},
	{Name: "themes", Start: 0x45C870, End: 0x45E08C},
	{Name: "tmsg", Start: 0x45E08C, End: 0x45E151},
	{Name: "town", Start: 0x45E151, End: 0x46019B},
	{Name: "towners", Start: 0x46019B, End: 0x4618A5},
	{Name: "track", Start: 0x4618A5, End: 0x4619A7},
	{Name: "trigs", Start: 0x4619A7, End: 0x462C6D},
	{Name: "wave", Start: 0x462C6D, End: 0x463060},
	{Name: "world", Start: 0x463060, End: 0x46971A},
	{Name: "_crt", Start: 0x46971A, End: 0x477470},
	{Name: "pkware", Start: 0x477470, End: 0x479000},
}

// ref: https://github.com/sanctuary/notes/blob/master/rdata/README.md
var rdataFiles = []*SourceFile{
	{Name: "_idata", Start: 0x479000, End: 0x479400},
	{Name: "_crt", Start: 0x479400, End: 0x479404},
	{Name: "capture", Start: 0x479404, End: 0x479424},
	{Name: "control", Start: 0x479424, End: 0x479658},
	{Name: "cursor", Start: 0x479658, End: 0x479BF8},
	{Name: "diablo", Start: 0x479BF8, End: 0x479C24},
	{Name: "drlg_l1", Start: 0x479C24, End: 0x479F84},
	{Name: "drlg_l3", Start: 0x479F84, End: 0x47A2D0},
	{Name: "drlg_l4", Start: 0x47A2D0, End: 0x47A460},
	{Name: "dthread", Start: 0x47A460, End: 0x47A464},
	{Name: "dx", Start: 0x47A464, End: 0x47A468},
	{Name: "effects", Start: 0x47A468, End: 0x47A474},
	{Name: "engine", Start: 0x47A474, End: 0x47A480},
	{Name: "exception", Start: 0x47A480, End: 0x47A48C},
	{Name: "gmenu", Start: 0x47A48C, End: 0x47A544},
	{Name: "help", Start: 0x47A544, End: 0x47AE20},
	{Name: "init", Start: 0x47AE20, End: 0x47AE40},
	{Name: "interfac", Start: 0x47AE40, End: 0x47AE60},
	{Name: "inv", Start: 0x47AE60, End: 0x47B0A8},
	{Name: "items", Start: 0x47B0A8, End: 0x47F048},
	{Name: "lighting", Start: 0x47F048, End: 0x47F070},
	{Name: "log", Start: 0x47F070, End: 0x47F074},
	{Name: "mainmenu", Start: 0x47F074, End: 0x47F078},
	{Name: "minitext", Start: 0x47F078, End: 0x47F130},
	{Name: "monster", Start: 0x47F130, End: 0x47F144},
	{Name: "movie", Start: 0x47F144, End: 0x47F148},
	{Name: "mpqapi", Start: 0x47F148, End: 0x47F14C},
	{Name: "msg", Start: 0x47F14C, End: 0x47F150},
	{Name: "msgcmd", Start: 0x47F150, End: 0x47F154},
	{Name: "multi", Start: 0x47F154, End: 0x47F164},
	{Name: "nthread", Start: 0x47F164, End: 0x47F168},
	{Name: "hero", Start: 0x47F168, End: 0x47F16C},
	{Name: "palette", Start: 0x47F16C, End: 0x47F1B0},
	{Name: "path", Start: 0x47F1B0, End: 0x47F1C0},
	{Name: "pfile", Start: 0x47F1C0, End: 0x47F204},
	{Name: "player", Start: 0x47F204, End: 0x47F230},
	{Name: "plrmsg", Start: 0x47F230, End: 0x47F238},
	{Name: "scrollrt", Start: 0x47F238, End: 0x47F24C},
	{Name: "sound", Start: 0x47F24C, End: 0x4802AC},
	{Name: "towners", Start: 0x4802AC, End: 0x4802D0},
	{Name: "track", Start: 0x4802D0, End: 0x4802D4},
	{Name: "wave", Start: 0x4802D4, End: 0x4802D8},
	{Name: "_crt", Start: 0x4802D8, End: 0x483000},
}

// ref: https://github.com/sanctuary/notes/blob/master/data/README.md
var dataFiles = []*SourceFile{
	{Name: "_crt", Start: 0x483000, End: 0x4830B8},
	{Name: "appfat", Start: 0x4830B8, End: 0x483B10},
	{Name: "automap", Start: 0x483B10, End: 0x483B90},
	{Name: "codec", Start: 0x483B90, End: 0x483BAC},
	{Name: "pkware", Start: 0x483BAC, End: 0x483C2C},
	{Name: "control", Start: 0x483C2C, End: 0x484250},
	{Name: "cursor", Start: 0x484250, End: 0x4842A8},
	{Name: "debug", Start: 0x4842A8, End: 0x4842E4},
	{Name: "pkware", Start: 0x4842E4, End: 0x484364},
	{Name: "diablo", Start: 0x484364, End: 0x4846B0},
	{Name: "doom", Start: 0x4846B0, End: 0x4846F8},
	{Name: "pkware", Start: 0x4846F8, End: 0x484778},
	{Name: "drlg_l1", Start: 0x484778, End: 0x4847D8},
	{Name: "pkware", Start: 0x4847D8, End: 0x484858},
	{Name: "drlg_l2", Start: 0x484858, End: 0x48613C},
	{Name: "pkware", Start: 0x48613C, End: 0x4861BC},
	{Name: "drlg_l4", Start: 0x4861BC, End: 0x4862B0},
	{Name: "dthread", Start: 0x4862B0, End: 0x4862F4},
	{Name: "dx", Start: 0x4862F4, End: 0x486370},
	{Name: "effects", Start: 0x486370, End: 0x48D6F0},
	{Name: "pkware", Start: 0x48D6F0, End: 0x48D770},
	{Name: "engine", Start: 0x48D770, End: 0x48D7C4},
	{Name: "error", Start: 0x48D7C4, End: 0x48DE80},
	{Name: "exception", Start: 0x48DE80, End: 0x48E1B8},
	{Name: "gamemenu", Start: 0x48E1B8, End: 0x48E358},
	{Name: "gendung", Start: 0x48E358, End: 0x48E3E8},
	{Name: "gmenu", Start: 0x48E3E8, End: 0x48E44C},
	{Name: "help", Start: 0x48E44C, End: 0x48E488},
	{Name: "init", Start: 0x48E488, End: 0x48E810},
	{Name: "interfac", Start: 0x48E810, End: 0x48E9A8},
	{Name: "inv", Start: 0x48E9A8, End: 0x48EA8C},
	{Name: "items", Start: 0x48EA8C, End: 0x49387C},
	{Name: "lighting", Start: 0x49387C, End: 0x4947C0},
	{Name: "loadsave", Start: 0x4947C0, End: 0x4947D4},
	{Name: "log", Start: 0x4947D4, End: 0x494898},
	{Name: "mainmenu", Start: 0x494898, End: 0x4948F8},
	{Name: "minitext", Start: 0x4948F8, End: 0x494948},
	{Name: "missiles", Start: 0x494948, End: 0x497E08},
	{Name: "monster", Start: 0x497E08, End: 0x49EEF8},
	{Name: "mpqapi", Start: 0x49EEF8, End: 0x49EFA8},
	{Name: "msg", Start: 0x49EFA8, End: 0x49F070},
	{Name: "_crt", Start: 0x49F070, End: 0x49F08C},
	{Name: "multi", Start: 0x49F08C, End: 0x49F204},
	{Name: "nthread", Start: 0x49F204, End: 0x49F288},
	{Name: "objects", Start: 0x49F288, End: 0x4A0D08},
	{Name: "palette", Start: 0x4A0D08, End: 0x4A0D70},
	{Name: "path", Start: 0x4A0D70, End: 0x4A0D7C},
	{Name: "pfile", Start: 0x4A0D7C, End: 0x4A0EF8},
	{Name: "player", Start: 0x4A0EF8, End: 0x4A1AAC},
	{Name: "plrmsg", Start: 0x4A1AAC, End: 0x4A1ABC},
	{Name: "portal", Start: 0x4A1ABC, End: 0x4A1AE0},
	{Name: "quests", Start: 0x4A1AE0, End: 0x4A1E08},
	{Name: "restricted", Start: 0x4A1E08, End: 0x4A1E40},
	{Name: "pkware", Start: 0x4A1E40, End: 0x4A1EC0},
	{Name: "scrollrt", Start: 0x4A1EC0, End: 0x4A208C},
	{Name: "setmaps", Start: 0x4A208C, End: 0x4A22D4},
	{Name: "sound", Start: 0x4A22D4, End: 0x4A23C8},
	{Name: "spell", Start: 0x4A23C8, End: 0x4A2D5C},
	{Name: "stores", Start: 0x4A2D5C, End: 0x4B2584},
	{Name: "themes", Start: 0x4B2584, End: 0x4B26A4},
	{Name: "town", Start: 0x4B26A4, End: 0x4B2724},
	{Name: "towners", Start: 0x4B2724, End: 0x4B2F78},
	{Name: "trigs", Start: 0x4B2F78, End: 0x4B325C},
	{Name: "world", Start: 0x4B325C, End: 0x4B3550},
	{Name: "_crt", Start: 0x4B3550, End: 0x4B7020},
	{Name: "pkware", Start: 0x4B7020, End: 0x4B7930},
}

// ref: https://github.com/sanctuary/notes/blob/master/bss/README.md
var bssFiles = []*SourceFile{
	{Name: "_crt", Start: 0x4B7930, End: 0x4B7934},
	{Name: "appfat", Start: 0x4B7934, End: 0x4B7A40},
	{Name: "automap", Start: 0x4B7A40, End: 0x4B84CC},
	{Name: "control", Start: 0x4B84CC, End: 0x4B8C9C},
	{Name: "cursor", Start: 0x4B8C9C, End: 0x4B8CD8},
	{Name: "dead", Start: 0x4B8CD8, End: 0x4BD2FC},
	{Name: "debug", Start: 0x4BD2FC, End: 0x525514},
	{Name: "diablo", Start: 0x525514, End: 0x525750},
	{Name: "doom", Start: 0x525750, End: 0x525764},
	{Name: "drlg_l1", Start: 0x525764, End: 0x5276C8},
	{Name: "drlg_l2", Start: 0x5276C8, End: 0x528378},
	{Name: "drlg_l3", Start: 0x528378, End: 0x5289C4},
	{Name: "drlg_l4", Start: 0x5289C4, End: 0x52A4E0},
	{Name: "dthread", Start: 0x52A4E0, End: 0x52A510},
	{Name: "dx", Start: 0x52A510, End: 0x52A550},
	{Name: "effects", Start: 0x52A550, End: 0x52A564},
	{Name: "encrypt", Start: 0x52A564, End: 0x52B968},
	{Name: "engine", Start: 0x52B968, End: 0x52B9A0},
	{Name: "error", Start: 0x52B9A0, End: 0x52B9F4},
	{Name: "exception", Start: 0x52B9F4, End: 0x52BA00},
	{Name: "gendung", Start: 0x52BA00, End: 0x634460},
	{Name: "gmenu", Start: 0x634460, End: 0x634490},
	{Name: "help", Start: 0x634490, End: 0x634968},
	{Name: "init", Start: 0x634968, End: 0x634CA8},
	{Name: "interfac", Start: 0x634CA8, End: 0x634CB8},
	{Name: "inv", Start: 0x634CB8, End: 0x634CC4},
	{Name: "items", Start: 0x634CC4, End: 0x6414E8},
	{Name: "lighting", Start: 0x6414E8, End: 0x646A2C},
	{Name: "loadsave", Start: 0x646A2C, End: 0x646A30},
	{Name: "log", Start: 0x646A30, End: 0x646CE0},
	{Name: "mainmenu", Start: 0x646CE0, End: 0x646CF4},
	{Name: "minitext", Start: 0x646CF4, End: 0x646D18},
	{Name: "missiles", Start: 0x646D18, End: 0x64CCE0},
	{Name: "monster", Start: 0x64CCE0, End: 0x659AF4},
	{Name: "movie", Start: 0x659AF4, End: 0x659B00},
	{Name: "mpqapi", Start: 0x659B00, End: 0x65AB18},
	{Name: "msg", Start: 0x65AB18, End: 0x6761A0},
	{Name: "msgcmd", Start: 0x6761A0, End: 0x6761B8},
	{Name: "multi", Start: 0x6761B8, End: 0x679700},
	{Name: "nthread", Start: 0x679700, End: 0x679768},
	{Name: "objects", Start: 0x679768, End: 0x67D7C8},
	{Name: "hero", Start: 0x67D7C8, End: 0x67D7CC},
	{Name: "palette", Start: 0x67D7CC, End: 0x67E3D8},
	{Name: "path", Start: 0x67E3D8, End: 0x6862E0},
	{Name: "pfile", Start: 0x6862E0, End: 0x686430},
	{Name: "player", Start: 0x686430, End: 0x69B7D0},
	{Name: "plrmsg", Start: 0x69B7D0, End: 0x69BC98},
	{Name: "portal", Start: 0x69BC98, End: 0x69BD00},
	{Name: "quests", Start: 0x69BD00, End: 0x69BEF8},
	{Name: "scrollrt", Start: 0x69BEF8, End: 0x69EFB0},
	{Name: "sha1", Start: 0x69EFB0, End: 0x69F0C4},
	{Name: "sound", Start: 0x69F0C4, End: 0x69F108},
	{Name: "stores", Start: 0x69F108, End: 0x6AA708},
	{Name: "sync", Start: 0x6AA708, End: 0x6AAA38},
	{Name: "themes", Start: 0x6AAA38, End: 0x6AAC14},
	{Name: "tmsg", Start: 0x6AAC14, End: 0x6AAC18},
	{Name: "towners", Start: 0x6AAC18, End: 0x6ABAB8},
	{Name: "track", Start: 0x6ABAB8, End: 0x6ABAC8},
	{Name: "trigs", Start: 0x6ABAC8, End: 0x6ABB34},
	{Name: "wave", Start: 0x6ABB34, End: 0x6ABB38},
	{Name: "_crt", Start: 0x6ABB38, End: 0x6AE000},
}

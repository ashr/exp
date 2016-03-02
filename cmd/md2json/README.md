# md2json

`md2json` is a tool for converting notes from Markdown to JSON format.

## Installation

```
$ go get github.com/sanctuary/exp/cmd/md2json
```

## Usage

```
md2json FILE...
```

## Examples

Input: [functions/towners.md](https://raw.githubusercontent.com/sanctuary/notes/master/functions/towners.md)

```
$ md2json functions/towners.md
```

Output:

```json
{
    "0x46019B": "// towners_get_num_from_id returns the towner number (towners array index) of\n// the given towner ID.\nint __fastcall towners_get_num_from_id(towner_id towner_id);\n",
    "0x4601C1": "// towners_init_facing_cels initializes the CEL graphics for each facing\n// direction.\nvoid __fastcall towners_init_facing_cels(void *towner_cel, void **facing_cels);\n",
    "0x4601FB": "// towners_init_anim initializes the animation of the given NPC.\nvoid __fastcall towners_init_anim(int towner_num, void *active_cel, int nframes, int nticks_per_frame);\n",
    "0x46022F": "// towners_place places the given NPC on the map.\nvoid __fastcall towners_place(int towner_num, int frame_width, bool32_t targetable, towner_id towner_id, int col, int row, towner_anim_seq_id towner_anim_seq_id, int unused);\n",
    "0x4602C4": "// towners_init_gossip initializes quest gossip of the given NPC.\nvoid __fastcall towners_init_gossip(int towner_num);\n",
    "0x460311": "// towners_init_griswold initializes Griswold the Blacksmith.\nvoid towners_init_griswold();\n",
    "0x4603A0": "// towners_init_odgen initializes Ogden the Tavern owner.\nvoid towners_init_odgen();\n",
    "0x460436": "// towners_init_wounded_townsman initializes the Wounded Townsman.\nvoid towners_init_wounded_townsman();\n",
    "0x4604C6": "// towners_init_adria initializes Adria the Witch.\nvoid towners_init_adria();\n",
    "0x460555": "// towners_init_gillian initializes Gillian the Barmaid.\nvoid towners_init_gillian();\n",
    "0x4605E4": "// towners_init_wirt initializes Wirt the Peg-legged boy.\nvoid towners_init_wirt();\n",
    "0x46067A": "// towners_init_pepin initializes Pepin the Healer.\nvoid towners_init_pepin();\n",
    "0x460709": "// towners_init_cain initializes Cain the Elder.\nvoid towners_init_cain();\n",
    "0x460798": "// towners_init_farnham initializes Farnham the Drunk.\nvoid towners_init_farnham();\n",
    "0x460827": "// towners_init_cows initializes the Cow NPCs.\nvoid towners_init_cows();\n",
    "0x460976": "// towners_init initializes the NPCs of Tristram.\nvoid towners_init();\n",
    "0x4609C3": "// towners_cleanup releases resources used by NPCs.\nvoid towners_cleanup();\n",
    "0x460A05": "// towners_stop_interaction stops interaction with distant players.\nvoid __fastcall towners_stop_interaction(int towner_num);\n",
    "0x460A78": "// towners_update_logic_griswold updates the logic of Griswold each game tick;\n// stops interaction with distant players.\nvoid towners_update_logic_griswold();\n",
    "0x460A86": "// towners_update_logic_ogden updates the logic of Ogden each game tick; stops interaction with distant players.\nvoid towners_update_logic_ogden();\n",
    "0x460A95": "// towners_update_logic_wounded_townsman updates the logic of the Wounded\n// Townsman each game tick; stops interaction with distant players, and updates\n// quest events.\nvoid towners_update_logic_wounded_townsman();\n",
    "0x460B0D": "// towners_update_logic_pepin updates the logic of Pepin each game tick; stops\n// interaction with distant players.\nvoid towners_update_logic_pepin();\n",
    "0x460B1C": "// towners_update_logic_cain updates the logic of Cain each game tick; stops\n// interaction with distant players.\nvoid towners_update_logic_cain();\n",
    "0x460B2B": "// towners_update_logic_farnham updates the logic of Farnham each game tick; stops interaction with distant players.\nvoid towners_update_logic_farnham();\n",
    "0x460B3A": "// towners_update_logic_wirt updates the logic of Wirt each game tick; stops\n// interaction with distant players.\nvoid towners_update_logic_wirt();\n",
    "0x460B49": "// towners_update_logic_adria updates the logic of Adria each game tick; stops\n// interaction with distant players.\nvoid towners_update_logic_adria();\n",
    "0x460B58": "// towners_update_logic_gillian updates the logic of Gillain each game tick;\n// stops interaction with distant players.\nvoid towners_update_logic_gillian();\n",
    "0x460B67": "// towners_update_logic_cow updates the logic of the Cows each game tick; stops interaction with distant players.\nvoid towners_update_logic_cows();\n",
    "0x460B76": "// towners_update updates the logic and graphics of NPCs each game tick.\nvoid towners_update();\n"
}
```

## Public domain

The source code and any original content of this repository is hereby released into the [public domain].

[public domain]: https://creativecommons.org/publicdomain/zero/1.0/

declare !addr !{!"0x401EF4"}                void @automap_show()
declare !addr !{!"0x405181"}                void @control_cleanup()
declare !addr !{!"0x417518"} x86_fastcallcc void @engine_set_seed(i32 %seed)
declare !addr !{!"0x41752C"}                i32 @engine_rand()
declare !addr !{!"0x4175E8"} x86_fastcallcc void @engine_mem_free(i8* %ptr)
declare !addr !{!"0x41804E"} x86_fastcallcc void @error_add(i8 %error_id)

; External functions from libc.
declare !addr !{!"0x46AA40"} external x86_stdcallcc i32 @abs(i32 %x)

declare !addr !{!"0x401000"}                void @j__crt_cpp_init()
declare !addr !{!"0x401005"}                void @_crt_cpp_init()
declare !addr !{!"0x4010CE"} x86_fastcallcc void @appfat_get_DD_error_string(i32 %error_code, i8* %error_buf, i32 %error_buf_len)
declare !addr !{!"0x401831"} x86_fastcallcc void @appfat_get_DS_error_string(i32 %error_code, i8* %error_buf, i32 %error_buf_len)
declare !addr !{!"0x401EF4"}                void @automap_show()
declare !addr !{!"0x404BEB"} x86_fastcallcc void @control_press_panel_button(i32 %panel_button_id)
declare !addr !{!"0x404C00"}                void @control_check_panel_button_press()
declare !addr !{!"0x405181"}                void @control_cleanup()
declare !addr !{!"0x417518"} x86_fastcallcc void @engine_set_seed(i32 %seed)
declare !addr !{!"0x41752C"}                i32 @engine_rand()
declare !addr !{!"0x4175E8"} x86_fastcallcc void @engine_mem_free(i8* %ptr)
declare !addr !{!"0x41804E"} x86_fastcallcc void @error_add(i8 %error_id)


; External functions.
declare !addr !{!"0x4697C2"} external x86_stdcallcc i1 @SErrGetErrorStr(i32 %error_code, i8* %dst, i32 %size)
declare !addr !{!"0x469990"} external x86_stdcallcc i32 @strlen(i8*)
declare !addr !{!"0x46AA40"} external x86_stdcallcc i32 @abs(i32 %x)
declare !addr !{!"0x479138"} external x86_stdcallcc i32 @FormatMessageA(i32 %dwFlags, i8* %lpSource, i32 %dwMessageId, i32 %dwLanguageId, i8* %lpBuffer, i32 %nSize, i8* %Arguments) ; TODO: Fix type of %Arguments, should be va_list*.
declare !addr !{!"0x4793E8"} external               i32 @wsprintfA(i8*, i8*, ...)

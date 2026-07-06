add_executable(new new.c)
target_link_libraries(new strings)
add_test(NAME new COMMAND new)

add_executable(push_cstr push_cstr.c)
target_link_libraries(push_cstr strings)
add_test(NAME push_cstr COMMAND push_cstr)

add_executable(push push.c)
target_link_libraries(push strings)
add_test(NAME push COMMAND push)

add_executable(ins ins.c)
target_link_libraries(ins strings)
add_test(NAME ins COMMAND ins)

add_executable(ins_cstr ins_cstr.c)
target_link_libraries(ins_cstr strings)
add_test(NAME ins_cstr COMMAND ins_cstr)

add_executable(ins_str ins_str.c)
target_link_libraries(ins_str strings)
add_test(NAME ins_str COMMAND ins_str)

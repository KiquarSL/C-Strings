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

add_executable(get get.c)
target_link_libraries(get strings)
add_test(NAME get COMMAND get)

add_executable(subs subs.c)
target_link_libraries(subs strings)
add_test(NAME subs COMMAND subs)

add_executable(split split.c)
target_link_libraries(split strings)
add_test(NAME split COMMAND split)

add_executable(finds finds.c)
target_link_libraries(finds strings)
add_test(NAME finds COMMAND finds)

add_executable(rep rep.c)
target_link_libraries(rep strings)
add_test(NAME rep COMMAND rep)

add_executable(pushf pushf.c)
target_link_libraries(pushf strings)
add_test(NAME pushf COMMAND pushf)

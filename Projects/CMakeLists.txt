add_executable(blink
        Main.c
)

target_link_libraries(blink pico_stdlib freertos)
pico_add_extra_outputs(blink)
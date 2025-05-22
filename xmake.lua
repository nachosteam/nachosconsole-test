add_rules("mode.debug", "mode.release")

target("nc-test")
    set_kind("binary")
    set_languages("c++23")
    add_files("src/*.cpp")

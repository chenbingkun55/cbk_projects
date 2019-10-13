-- add_requires("fmt")
-- add_packages("fmt")

-- the debug mode
if is_mode("debug") then
    
    -- enable the debug symbols
    set_symbols("debug")

    -- disable optimization
    set_optimize("none")
end  

-- imgui
target("imgui")
    set_kind("shared")

    add_linkdirs("/usr/lib/x86_64-linux-gnu/","/usr/local/lib")
    -- add link lib
    add_links("glfw3","GL","Xrandr","X11","Xi","Xxf86vm","pthread","dl","Xinerama","m","rt","Xcursor")

    add_headerfiles("libs/imgui/*.h")
    add_files("libs/imgui/*.cpp")

    add_includedirs("libs/imgui", {public = true})

-- tinyxml
target("tinyxml")
    set_kind("shared")

    add_headerfiles("libs/tinyxml/*.h")
    add_files("libs/tinyxml/*.cpp")

    add_includedirs("libs/tinyxml", {public = true})

-- fmt
target("fmt")
    set_kind("shared")

    add_headerfiles("libs/fmt/include/fmt/*.h")
    add_files("libs/fmt/src/*.cc")

    add_includedirs("libs/fmt/include", {public = true})

-- test_imgui
target("test_imgui")
    set_kind("binary")

    add_files("apps/test_imgui/main.cpp")

    add_cxxflags("-fPIC")
    add_deps("imgui", "fmt", "tinyxml")

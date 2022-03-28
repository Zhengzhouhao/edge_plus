includes("VC-LTL5.lua")

add_defines("UNICODE")

target("edge_plus")
    set_kind("shared")
    set_targetdir("$(buildir)/release")
    set_basename("KBDUS")
    add_files("src/*.cpp")
    add_links("user32")
    after_build(function (target)
        os.rm("$(buildir)/release/KBDUS.exp")
        os.rm("$(buildir)/release/KBDUS.lib")
    end)

add_library(reductions_lib
    sat.cpp
    three_sat.cpp
    three_sat_sat.cpp
)

add_executable(reductions
    main.cpp
)

target_link_libraries(reductions reductions_lib)
cmake_minimum_required(VERSION 3.29)
project(lab4)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(
  include
  include/nodes
  include/results
)

add_executable(
  lab4 src/main.cpp

  # Errors
  include/results/error.h
  src/results/error.cpp

  # Results
  include/results/result.h
  include/results/result_void.h

  # Base node
  include/nodes/node.h
  src/nodes/node.cpp

  # Functions
  include/nodes/functions/function.h
  src/nodes/functions/function.cpp

  include/nodes/functions/cos.h
  src/nodes/functions/cos.cpp

  include/nodes/functions/sin.h
  src/nodes/functions/sin.cpp

  # Numbers
  include/nodes/numbers/number.h
  src/nodes/numbers/number.cpp

  include/nodes/numbers/const.h
  src/nodes/numbers/const.cpp

  include/nodes/numbers/variable.h
  src/nodes/numbers/variable.cpp

  # Operators
  include/nodes/operators/operator.h
  src/nodes/operators/operator.cpp

  include/nodes/operators/add.h
  src/nodes/operators/add.cpp

  include/nodes/operators/div.h
  src/nodes/operators/div.cpp

  include/nodes/operators/mul.h
  src/nodes/operators/mul.cpp

  include/nodes/operators/sub.h
  src/nodes/operators/sub.cpp

  # Tree
  include/tree.h
  src/tree.cpp

  # Saver
  include/results/saver.h
)

cmake_minimum_required(VERSION 3.29)
project(lab3)

set(CMAKE_CXX_STANDARD 11)

include_directories(
  include
)

add_executable(
  lab3 main.cpp

  # Base node
  include/nodes/base.h
      src/nodes/base.cpp

  # Functions
  include/nodes/functions/function.h
      src/nodes/functions/function.cpp

  include/nodes/functions/sin.h
      src/nodes/functions/sin.cpp

  include/nodes/functions/cos.h
      src/nodes/functions/cos.cpp

  # Operators
  include/nodes/operators/operator.h
      src/nodes/operators/operator.cpp

  include/nodes/operators/add.h
      src/nodes/operators/add.cpp

  include/nodes/operators/sub.h
      src/nodes/operators/sub.cpp

  include/nodes/operators/mul.h
      src/nodes/operators/mul.cpp

  include/nodes/operators/div.h
      src/nodes/operators/div.cpp

  # Numbers
  include/nodes/numbers/const.h
      src/nodes/numbers/const.cpp

  include/nodes/numbers/number.h
      src/nodes/numbers/number.cpp

  include/nodes/numbers/variable.h
      src/nodes/numbers/variable.cpp

  # Tree
  include/tree.h
      src/tree.cpp

  # CLI
  include/cli.h
      src/cli.cpp
)

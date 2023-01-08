// clang-format off
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
//  Written By : Michael R. Nowak                Environment : ubuntu:latest               //
//  Date ......: 2022/02/07                      Compiler ...: clang-10                    //
/////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////
// clang-format on
/////////////////////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
/////////////////////////////////////////////////////////////////////////////////////////////
#ifndef CATCH_CONFIG_MAIN
#  define CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                                 Includes //
/////////////////////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

#include "board.hpp"

/////////////////////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
/////////////////////////////////////////////////////////////////////////////////////////////
constexpr int kBoardWidth = 7;
constexpr int kBoardHeight = 6;

bool AreEqual(DiskType solution[][kBoardWidth],
              DiskType student[][kBoardWidth]) {
  for (int i = 0; i < kBoardHeight; ++i) {
    for (int j = 0; j < kBoardWidth; ++j) {
      if (solution[i][j] != student[i][j]) return false;
    }
  }
  return true;
}



/////////////////////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
/////////////////////////////////////////////////////////////////////////////////////////////

TEST_CASE("Board initialization", "[board_init]") {
  // SECTION("Can use sections") {}
  // clang-format off
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  REQUIRE(AreEqual(solution, student.board));
}

TEST_CASE("Board initialization False", "[board_init_false]") {
  // SECTION("Can use sections") {}
  // clang-format off
  DiskType solution[kBoardHeight][kBoardWidth] = { 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty}, 
    {DiskType::kPlayer1, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty, DiskType::kEmpty} 
  };
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  REQUIRE_FALSE(AreEqual(solution, student.board));
}

TEST_CASE("BoardLocationOutBounds", "[out_bounds]") {
  // SECTION("Can use sections") {}
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  REQUIRE_FALSE(BoardLocationInBounds(kBoardWidth, kBoardHeight));
  REQUIRE_FALSE(BoardLocationInBounds(-1, -1));
  REQUIRE_FALSE(BoardLocationInBounds(kBoardWidth - 1, -1));
  REQUIRE_FALSE(BoardLocationInBounds(-1, kBoardHeight - 1));
}

TEST_CASE("BoardLocationInBounds", "[in_bounds]") {
  // SECTION("Can use sections") {}
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  REQUIRE(BoardLocationInBounds(0, 0));
  REQUIRE(BoardLocationInBounds(kBoardHeight - 1, kBoardWidth - 1));
}

TEST_CASE("Hor Winner", "[hor_winner]") {
  // SECTION("Can use sections") {}
  // clang-format off
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  for (unsigned int i = 0; i < 3; ++i) {
    DropDiskToBoard(student, DiskType::kPlayer1, i);
  }
  REQUIRE_FALSE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kHorizontal));
}

TEST_CASE("Vert Winner", "[vert_winner]") {
  // SECTION("Can use sections") {}
  // clang-format off
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  REQUIRE_FALSE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kVertical));
}

TEST_CASE("Left Diagonal Winner", "[left_winner]") {
  // SECTION("Can use sections") {}
  // clang-format off
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  REQUIRE_FALSE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kLeftDiag));
}

TEST_CASE("Right Diagonal Winner", "[right_winner]") {
  // SECTION("Can use sections") {}
  // clang-format off
  // clang-format on
  Board student;  // NOLINT
  InitBoard(student);
  REQUIRE_FALSE(SearchForWinner(student, DiskType::kPlayer2, WinningDirection::kRightDiag));
}
/////////////////////////////////////////////////////////////////////////////////////////////
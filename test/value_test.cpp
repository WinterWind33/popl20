// Copyright (C) 2022 Andrea Ballestrazzi

#include <catch2/catch_template_test_macros.hpp>
#include <popl.hpp>

// C++ STL
#include <string_view>
#include <memory>

namespace test{

    template<typename T>
    static void assertValueCorrectlyConstructed(
        const popl::Value<T>& actual,
        const std::string& expectedShortName,
        const std::string& expectedLongName,
        const std::string& expectedDescription) {
        CHECK(actual.short_name() == expectedShortName[0]);
        CHECK(actual.long_name() == expectedLongName);
        CHECK(actual.description() == expectedDescription);
    }

} // namespace test

TEMPLATE_TEST_CASE("Value class unit test", "[unit][value]",
    std::string, std::int32_t) {
    SECTION("Constructors tests") {
        SECTION("When valid values are passed to constructors") {
            static constexpr std::string_view SHORT_NAME{"t"};
            static constexpr std::string_view LONG_NAME{"test"};
            static constexpr std::string_view VALUE_DESCRIPTION{"Test value description"};

            SECTION("Constructor #1 should correctly set the value's state") {
                std::unique_ptr<popl::Value<TestType>> valueUnderTest{};

                // Precondition
                REQUIRE_NOTHROW(valueUnderTest
                    = std::make_unique<popl::Value<TestType>>(std::string{SHORT_NAME}, std::string{LONG_NAME}, std::string{VALUE_DESCRIPTION}));

                test::assertValueCorrectlyConstructed(*valueUnderTest, std::string{SHORT_NAME}, std::string{LONG_NAME}, std::string{VALUE_DESCRIPTION});
            }
        }

        SECTION("When invalid values are passed to constructors") {
            static constexpr std::string_view INVALID_SHORT_NAME{"test_short_name"};
            static constexpr std::string_view VALID_LONG_NAME{"test"};
            static constexpr std::string_view VALID_DESCRIPTION{"Test value description"};

            SECTION("When passing an invalid short name") {
                SECTION("Constructor #1 should throw an std::invalid_argument exception") {
                    REQUIRE_THROWS_AS(
                        popl::Value<TestType>(std::string{INVALID_SHORT_NAME}, std::string{VALID_LONG_NAME}, std::string{VALID_DESCRIPTION}),
                        std::invalid_argument);
                }
            }
        }
    }
}

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "Awards.h"


using namespace awards;
using namespace testing;


//need to create a stub list
class StubRankList : public RankList
{
    public:
    std::string getNext()
    {
      return "korol";
    }
};

class MockAwardCeremonyActions : public AwardCeremonyActions
{
    public:
    MOCK_METHOD0(playAnthem, void());
    MOCK_METHOD0(turnOffTheLightsAndGoHome, void());
    MOCK_METHOD1(awardBronze, void (std::string recipient));
    MOCK_METHOD1(awardSilver, void(std::string recipient));
    MOCK_METHOD1(awardGold, void(std::string recipient));
};

//how to test performAwardCeremony function
TEST(AwardsTests, testperformAwardCeremony)
{
  MockAwardCeremonyActions action;
  StubRankList list;
  
  EXPECT_CALL(action, playAnthem());

  EXPECT_CALL(action, awardBronze(list.getNext()));

  EXPECT_CALL(action, awardSilver(list.getNext()));

  EXPECT_CALL(action, awardGold(list.getNext()));

  EXPECT_CALL(action, turnOffTheLightsAndGoHome());

  performAwardCeremony(list, action);
}
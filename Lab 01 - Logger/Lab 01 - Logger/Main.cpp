#include "GameLogger.h"

void PlayGame()
{
	GameLogger::Log(LogMsgType::Process ,"About to Play the game!\n");

	int   numPlayers = 3;
	int   numChatters = 17;
	float playPercent = 100.0f * numPlayers / numChatters;
	const char* const level = "Dark Ghoul Dungeon";
	const char* const chatroom = "Raid Chatroom";
	GameLogger::Log(LogMsgType::Process, "%d players are in %s, %d are in %s, %3.1f %% are playing!\n",
		numPlayers, level, numChatters, chatroom, playPercent);

	float numSecondsPlayed = 1234.6f;
	GameLogger::Log(LogMsgType::Process, "Done playing the game, elapsed time was %3.1f seconds!\n", numSecondsPlayed);
}

int main(/*int argc, char** argv*/)
{
	//printf("%s\n", argv[0]); // Shows the path of the exe
	if (!GameLogger::Initialize("..\\Debug\\", "CreepGame.log")) return 1;

	PlayGame();

	if (!GameLogger::Shutdown()) return 2;
	return 0;
}

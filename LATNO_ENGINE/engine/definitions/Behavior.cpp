#include "../declarations/Behavior.h"

namespace Latno
{
	std::vector<Latno::Behavior*> BehaviorList;

	void Behavior::AddTag(std::string TagToAdd)
	{
		TagVector.push_back(TagToAdd);
		int x = TagVector.size();
		DevLog::LOGLN('"' + TagToAdd + '"' + " added to TagVector at index position " + std::to_string(TagVector.size()), "MainLog");
	}

	void Behavior::RemoveTag(std::string TagToRemove)
	{
		for (int i = 0; i < TagVector.size() - 1; i++) {
			if (TagVector[i] == TagToRemove) {
				TagVector.erase(TagVector.begin() + i);
				DevLog::LOGLN('"' + TagToRemove + '"' + " removed from TagVector at index position " + std::to_string(i), "MainLog");
			}
		}

	}

	bool Behavior::IfHasTag(std::string Tag)
	{
		for (std::string element : TagVector)
			if (element == Tag) return true;
		return false;
	}
}
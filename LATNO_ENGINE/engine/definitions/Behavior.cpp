#include "../declarations/Behavior.h"

namespace Latno
{
	std::vector<Latno::Behavior*> BehaviorList;

	void Behavior::AddTag(std::string TagToAdd)
	{
		tagVector.push_back(TagToAdd);
		int x = tagVector.size();
		DevLog::LOGLN('"' + TagToAdd + '"' + " added to TagVector at index position " + std::to_string(tagVector.size()), "MainLog");
	}

	void Behavior::RemoveTag(std::string TagToRemove)
	{
		for (int i = 0; i < tagVector.size() - 1; i++) {
			if (tagVector[i] == TagToRemove) {
				tagVector.erase(tagVector.begin() + i);
				DevLog::LOGLN('"' + TagToRemove + '"' + " removed from TagVector at index position " + std::to_string(i), "MainLog");
			}
		}

	}

	bool Behavior::IfHasTag(std::string Tag)
	{
		for (std::string element : tagVector)
			if (element == Tag) return true;
		return false;
	}
}
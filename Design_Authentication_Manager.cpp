// Leetcode 1797

class AuthenticationManager {
public:
	int tt;
	unordered_map<string, pair<int, int>> mm;
	AuthenticationManager(int timeToLive) {
		this->tt = timeToLive;
	}

	void generate(string tokenId, int currentTime) {
		mm[tokenId] = { currentTime, currentTime + this->tt };
	}

	void renew(string tokenId, int currentTime) {
		auto ind = mm.find(tokenId);
		if (ind == mm.end()) return;
		if (currentTime <= ind->second.first) return;
		if (currentTime >= ind->second.second) return;
		ind->second.second = currentTime + this->tt;
	}

	int countUnexpiredTokens(int currentTime) {
		int res = 0;
		for (auto ind = mm.begin(); ind != mm.end(); ++ind) {
			if (currentTime >= ind->second.first && currentTime < ind->second.second) ++res;
		}
		return res;
	}
};

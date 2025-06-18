# CXX = g++
# CXXFLAGS = -Wall -std=c++17

# all: server client

# server: server/main.cpp server/socket_utils.cpp
# 	$(CXX) $(CXXFLAGS) -o build/server $^

# client: client/main.cpp
# 	$(CXX) $(CXXFLAGS) -o build/client $^

# clean:
# 	rm -f build/server build/client

CXX = g++
CXXFLAGS = -Wall -std=c++17
BUILD_DIR = build

all: $(BUILD_DIR)/server $(BUILD_DIR)/client

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/server: server/main.cpp server/socket_utils.cpp server/game_logic.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(BUILD_DIR)/client: client/main.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -rf $(BUILD_DIR)

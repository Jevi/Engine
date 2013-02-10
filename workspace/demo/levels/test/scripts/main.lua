local engine = Engine:GetInstance()
local levelSystem = engine:GetLevelSystem()
local entity = levelSystem:GetEntity("player")

while engine:GetAppState() == "Running" do
	io.write(entity:ToString(), "\n")
	Sleep()
end
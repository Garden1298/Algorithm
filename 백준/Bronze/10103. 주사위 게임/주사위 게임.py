chang_score = 100
sang_score = 100

n = int(input())

for _ in range(n):
    chang_dice, sang_dice = map(int, input().split())
    
    if chang_dice > sang_dice:
        sang_score -= chang_dice
    elif chang_dice < sang_dice:
        chang_score -= sang_dice
        
        
print(chang_score)
print(sang_score)
        
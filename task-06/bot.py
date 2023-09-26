import discord
from discord.ext import commands
import pandas as pd # for manipulating data recieved from the espn website
import os
from scraper import retrieve_live_scores

intents = discord.Intents.default()
intents.typing = False
intents.presences = False
intents.message_content = True 

bot = commands.Bot(command_prefix='!', intents=intents)

@bot.event
async def on_ready():
    print(f'Logged in as {bot.user.name}')

def save_live_scores_to_csv(team_data, score_status_data):
    df = pd.DataFrame({'Team': team_data, 'Score': [score for score, _ in score_status_data], 'Status': [status for _, status in score_status_data]})
    
    if not os.path.isfile('live_scores.csv'):
        df.to_csv('live_scores.csv', index=False)
    else:  
        df.to_csv('live_scores.csv', mode='a', header=False, index=False)

@bot.command()
async def livescore(ctx):
    team_data, score_status_data = retrieve_live_scores()

    if team_data and score_status_data:
        team = team_data[0]
        score, status = score_status_data[0]

    
        live_score_text = (
            f"Live Score : {team}\n"
            f"Status : {score}\n"
            f"Details : {status}\n"
        )

        await ctx.send(live_score_text)

        save_live_scores_to_csv(team_data, score_status_data)

    else:
        await ctx.send("Failed to retrieve the page.")


@bot.command()
async def csv(ctx):
    if os.path.isfile('live_scores.csv'):
        csv_file = discord.File('live_scores.csv')
        await ctx.send(file=csv_file)
    else:
        await ctx.send("No live scores history available.")
        # For getting the csv file

bot.remove_command('help')

@bot.command()
async def help(ctx):
    help_message = (
        "Here are the available commands:\n"
        "!livescore - Get live cricket scores.\n"
        "!csv - Get the CSV(Comma Separated Values) file of live scores history.\n"
        "!help - Shows this message.\n"
        "!hi - intro"
    )
    await ctx.send(help_message)

@bot.command(aliases=['hey','hello'])
async def hi(ctx):
    hi_message = (
        "Yo,wanna know livescores?\n"
        "try my commands\n"
        "start with !help"
    )
    await ctx.send(hi_message)
 


bot.run('MTE0ODkxNDcxMzkyMTYwNTY0Mg.GDqAzc.p_04XoFZf2QFT34_8uWkxFfYZ5plvWnnaW4TCI')

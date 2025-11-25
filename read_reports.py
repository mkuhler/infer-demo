import json

def print_cost_analysis():
  with open("infer-out/costs-report.json") as f:
    procedures = json.load(f)

  print(f"{'Function':<20} {'Location':<20} {'Estimated Cost'}")
  print("-" * 60)
  for proc in procedures:
    name = proc.get('procedure_name', '')
    loc = proc.get('loc', {})
    location = f"{loc.get('file','')}:{loc.get('lnum','')}"
    cost = proc.get('exec_cost', {}).get('hum', {}).get('big_o', '')
    print(f"{name:<20} {location:<30} {cost}")


print_cost_analysis()
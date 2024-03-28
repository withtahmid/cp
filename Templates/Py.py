import subprocess

def run_with_file_io(program_name, input_file_name, output_file_name):
  """
  Runs the specified program with input from a file and output to a file.

  Args:
      program_name: The name of your Python program (including ".py").
      input_file_name: The name of the file containing input data.
      output_file_name: The name of the file to write output to.
  """

  with open(input_file_name, "r") as f:
      input_data = f.read()

  # Choose either output redirection or capture (uncomment your preferred method)

  # Output redirection (simpler)
  subprocess.run(["python", program_name], input=input_data.encode(), stdout=open(output_file_name, "w"))

  # OR

  # Capture output as bytes (more flexible)
  # result = subprocess.run(["python", program_name], input=input_data.encode(), capture_output=True)
  # output_data = result.stdout.decode()
  # with open(output_file_name, "w") as f:
  #     f.write(output_data)

# Example usage (replace with your program name and file names)
program_name = "Py.py"
input_file_name = "input.txt"
output_file_name = "output.txt"

run_with_file_io(program_name, input_file_name, output_file_name)

print(f"Output written to: {output_file_name}")  # Informative message

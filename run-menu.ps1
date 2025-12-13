Param()

$root = Split-Path -Parent $MyInvocation.MyCommand.Definition
$exe = Join-Path $root "build\bitkitchen.exe"

if (-not (Test-Path $exe)) {
    Write-Host "`nplease build the project first (`cmake --build` in `build`).`n"
    exit 1
}

function Get-Format {
    Param([string]$label)
    do {
        $choice = Read-Host "choose $label format (1 bytes, 2 hex, 3 base64)"
        switch ($choice) {
            "1" { return "bytes" }
            "2" { return "hex" }
            "3" { return "base64" }
        }
        Write-Host "invalid selection"
    } while ($true)
}

$actions = @(
    @{ label = "hex conversion" ; action = $null }
    @{ label = "base64 conversion" ; action = $null }
    @{ label = "caesar cipher" ; action = "CAESAR"; param_prompt = "Caesar shift (e.g. 3)" }
    @{ label = "xor" ; action = "XOR"; param_prompt = "XOR key" }
    @{ label = "rc4" ; action = "RC4"; param_prompt = "RC4 key" }
    @{ label = "uppercase" ; action = "UPPERCASE" }
    @{ label = "lowercase" ; action = "LOWERCASE" }
    @{ label = "round-trip hex" ; action = $null }
)

Write-Host "`nbitkitchen quick menu`n"
for ($i = 0; $i -lt $actions.Count; $i++) {
    Write-Host (" [{0}] {1}" -f ($i + 1), $actions[$i].label)
}

do {
    $selection = Read-Host "`nchoose an option (number)"
    if ([int]::TryParse($selection, [ref]$null) -and $selection -ge 1 -and $selection -le $actions.Count) {
        break
    }
    Write-Host "invalid choice, try again."
} while ($true)

$selected = $actions[$selection - 1]
$inputFile = Read-Host "input file path"
$outputFile = Read-Host "output file path"
$inputFile = $inputFile.Trim()
$outputFile = $outputFile.Trim()
if ($inputFile.StartsWith("/") -or $inputFile.StartsWith("\")) {
    $inputFile = $inputFile.TrimStart("/", "\")
}
if ($outputFile.StartsWith("/") -or $outputFile.StartsWith("\")) {
    $outputFile = $outputFile.TrimStart("/", "\")
}
$inputFormat = Get-Format -label "input"
$outputFormat = Get-Format -label "output"
$actionArgs = @()
if ($selected.action) {
    $actionArgs += "--action"
    $actionArgs += $selected.action
    if ($selected.param_prompt) {
        $paramValue = Read-Host $selected.param_prompt
        if ($selected.action -eq "CAESAR") {
            $actionArgs += "--caesar-shift=$paramValue"
        } elseif ($selected.action -eq "RC4") {
            $actionArgs += "--rc4-key=$paramValue"
        } elseif ($selected.action -eq "XOR") {
            $actionArgs += "--xorkey=$paramValue"
        }
    }
}

$args = @("--in", $inputFile, "--input-format", $inputFormat, "--out", $outputFile, "--output-format", $outputFormat) + $actionArgs

Write-Host "`nrunning: $($selected.label)"
Write-Host "$exe $($args -join ' ')`n"

& "$exe" @($args)


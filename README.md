# HDR Utilities

Adds a function to Unreal that will retrieve the HDR calibration on Windows platforms for displays that have used the Windows 11 HDR calibration tool.



Function `GetPrimaryDisplayInformation()` (can be used in BP) will retrieve:
- The display name
- Min luminance
- Max luminance
- Max full-frame luminance

An ideal use-case for this is as the default values for HDR output, for users that have calibrated their HDR output in Windows 11. It will not return useful values on non-windows platforms, on < Win 11 platforms on Win 11 without HDR calibration.

To check if the values are usable, simply check if the `MaxFullFrameLuminance` or `Maxluminance` == 0. Note that this does not check for HDR support, as Unreal can already do that.

To set the HDR output nits, use `EnableHDRDisplayOutput` _and_ use CVar `r.HDR.Display.MaxLuminance`. Setting the `DisplayNits` with `EnableHDRDisplayOutput()` does not actually change the output nits, just sets the property in `UGameUserSettings`.

I would also recommend allowing the user to override these values and ensuring that your game outputs the correct values. You can profile your HDR output on an HDR display with [Reshade](https://reshade.me/) by using [Lilium](https://github.com/EndlesslyFlowering)'s [HDR and SDR analysus](https://github.com/EndlesslyFlowering/ReShade_HDR_shaders) (HDR analysis effect).

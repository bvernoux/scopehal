/***********************************************************************************************************************
*                                                                                                                      *
* libscopehal                                                                                                          *
*                                                                                                                      *
* Copyright (c) 2012-2024 Andrew D. Zonenberg and contributors                                                         *
* All rights reserved.                                                                                                 *
*                                                                                                                      *
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that the     *
* following conditions are met:                                                                                        *
*                                                                                                                      *
*    * Redistributions of source code must retain the above copyright notice, this list of conditions, and the         *
*      following disclaimer.                                                                                           *
*                                                                                                                      *
*    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the       *
*      following disclaimer in the documentation and/or other materials provided with the distribution.                *
*                                                                                                                      *
*    * Neither the name of the author nor the names of any contributors may be used to endorse or promote products     *
*      derived from this software without specific prior written permission.                                           *
*                                                                                                                      *
* THIS SOFTWARE IS PROVIDED BY THE AUTHORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED   *
* TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL *
* THE AUTHORS BE HELD LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES        *
* (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR       *
* BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT *
* (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE       *
* POSSIBILITY OF SUCH DAMAGE.                                                                                          *
*                                                                                                                      *
***********************************************************************************************************************/

/**
	@brief Declaration of BufferedSwitchMatrixOutputChannel
	@ingroup core
 */

#ifndef BufferedSwitchMatrixOutputChannel_h
#define BufferedSwitchMatrixOutputChannel_h

/**
	@brief An output channel of a buffered switch matrix
	@ingroup core
 */
class BufferedSwitchMatrixOutputChannel : public DigitalOutputChannel
{
public:

	BufferedSwitchMatrixOutputChannel(
		const std::string& hwname,
		SwitchMatrix* parent,
		const std::string& color = "#808080",
		size_t index = 0);

	virtual ~BufferedSwitchMatrixOutputChannel();

	virtual bool ValidateChannel(size_t i, StreamDescriptor stream) override;
	virtual void OnInputChanged(size_t i) override;

	///@brief Gets the switch matrix this channel is part of
	SwitchMatrix* GetSwitchMatrix()
	{ return dynamic_cast<SwitchMatrix*>(m_instrument); }

	///@brief Returns true if the channel has configurable output drive voltage
	bool MuxHasConfigurableDrive()
	{ return GetSwitchMatrix()->MuxHasConfigurableDrive(GetIndex()); }

	///@brief Gets the output port drive voltage
	float GetMuxOutputDrive()
	{ return GetSwitchMatrix()->GetMuxOutputDrive(GetIndex()); }

	/**
		@brief Sets the output port drive voltage

		@param v	Output drive voltage, in volts
	 */
	void SetMuxOutputDrive(float v)
	{ GetSwitchMatrix()->SetMuxOutputDrive(GetIndex(), v); }
};

#endif
